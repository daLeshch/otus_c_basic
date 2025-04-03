#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>

#include "CRC32.hpp"
#include "IO.hpp"

std::mutex cout_mutex;

/// @brief Переписывает последние 4 байта значением value
void replaceLastFourBytes(std::vector<char> &data, uint32_t value) {
  std::copy_n(reinterpret_cast<const char *>(&value), 4, data.end() - 4);
}

/**
 * @brief Формирует новый вектор с тем же CRC32, добавляя в конец оригинального
 * строку injection и дополнительные 4 байта
 * @details При формировании нового вектора последние 4 байта не несут полезной
 * нагрузки и подбираются таким образом, чтобы CRC32 нового и оригинального
 * вектора совпадали
 * @param original оригинальный вектор
 * @param injection произвольная строка, которая будет добавлена после данных
 * оригинального вектора
 * @return новый вектор
 */
struct Threads {
  const std::vector<char>* original;
  const std::string* injection;
  uint32_t originalCrc32;
  std::vector<char> result;
  std::atomic<bool>* found;
  uint32_t start;
  uint32_t end;
};

void threadWorker(Threads data) {
  std::vector<char> localResult(data.original->size() + data.injection->size() + 4);
  auto it = std::copy(data.original->begin(), data.original->end(), localResult.begin());
  std::copy(data.injection->begin(), data.injection->end(), it);

  for (uint32_t i = data.start; i < data.end && !data.found->load(); ++i) {
      replaceLastFourBytes(localResult, i);
      auto currentCrc32 = crc32(localResult.data(), localResult.size());

      if (currentCrc32 == data.originalCrc32) {
          std::lock_guard<std::mutex> lock(cout_mutex);
          if (!data.found->exchange(true)) {
              data.result = localResult;
              std::cout << "Success in thread\n";
          }
          return;
      }

      if (i % 1000000 == 0) {
          std::lock_guard<std::mutex> lock(cout_mutex);
          std::cout << "Progress in range [" << data.start << ", " << data.end 
                    << "]: " << static_cast<double>(i - data.start) / (data.end - data.start) 
                    << std::endl;
      }
  }
}

std::vector<char> hack(const std::vector<char> &original, const std::string &injection) {
  const uint32_t originalCrc32 = crc32(original.data(), original.size());
  const unsigned num_threads = std::thread::hardware_concurrency();
  std::vector<std::thread> threads;
  std::atomic<bool> found(false);
  std::vector<char> result;

  uint32_t maxVal = std::numeric_limits<uint32_t>::max();
  uint32_t range = maxVal / num_threads;

  std::vector<Threads> threadData(num_threads);

  for (unsigned i = 0; i < num_threads; ++i) {
      threadData[i].original = &original;
      threadData[i].injection = &injection;
      threadData[i].originalCrc32 = originalCrc32;
      threadData[i].found = &found;
      threadData[i].start = i * range;
      threadData[i].end = (i == num_threads - 1) ? maxVal : (i + 1) * range;
      
      threads.emplace_back(threadWorker, threadData[i]);
  }

  for (auto& thread : threads) {
      thread.join();
  }

  for (const auto& data : threadData) {
      if (!data.result.empty()) {
          result = data.result;
          break;
      }
  }

  if (result.empty()) {
      throw std::logic_error("Can't hack");
  }

  return result;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Call with two args: " << argv[0]
              << " <input file> <output file>\n";
    return 1;
  }

  try {
    const std::vector<char> data = readFromFile(argv[1]);
    const std::vector<char> badData = hack(data, "He-he-he");
    writeToFile(argv[2], badData);
  } catch (std::exception &ex) {
    std::cerr << ex.what() << '\n';
    return 2;
  }
  return 0;
}