#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <string> 
#include <fstream> 
#include <vector>
#include <sstream>
#include <algorithm>

bool number_check(int random){
    int num;
    std::cout << "Please, input your guess:\n";
    std::cin >> num;

    if (num < random) {
        std::cout << "Try greater then " << num << std::endl;
        return false;
    } else if (num > random) {
        std::cout << "Try less then " << num << std::endl;
        return false;
    } else {
        std::cout << "Good job!\nThe answer is: " << num << std::endl;
        return true;
    }

}

int randomizer(int lvl, int &game_max){
    if (lvl > 1){
        switch (lvl)
        {
        case 2:
            game_max = 49;
            break;
        case 3:
            game_max = 99;
            break;
        case 4:
            std::cout << "Please, enter maximum number." << std::endl;
            std::cin >> game_max;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    const int game_min = 0;

    std::srand(std::time(nullptr));

    return std::rand() % (game_max + 1);
}

void file_editing(const std::string &filename, std::string &username, int score){
    std::ofstream records_file(filename, std::ios::app);
    if (!records_file.is_open()){
        std::cerr << "Records file is missing!" << std::endl;
        return;
    }
    records_file << username << " ---- " << score << '\n';
    records_file.close();
}

void display_records(const std::string &filename){
    std::ifstream records_file(filename);
    if (!records_file.is_open()){
        std::cerr << "Unable to open!"<< filename << std::endl;
        return;
    }
    std::string line;
    std::cout << "Records:" << std::endl;
    while (std::getline(records_file, line)){
        std::cout << line << std::endl;
    }
    records_file.close();
}

int attempts(std::string line){
    std::stringstream ss;
    ss << line;
    int found = 0;
    std::string temp;

    while (ss >> temp){
        if (std::stringstream(temp) >> found){
        }
        temp = "";
    }
    return found;
}

void display_sorted(const std::string &filename){
    std::ifstream records_file(filename);
    if (!records_file.is_open()){
        std::cerr << "Unable to open " << filename << std::endl;
        return;
    }

    std::string line;
    std::vector<std::pair<std::string, int>> records;

    while (std::getline(records_file, line)){
        int score = attempts(line);
        records.emplace_back(line, score);
    }

    std::sort(records.begin(), records.end(), [](const auto& a, const auto& b) {
        return a.second < b.second; 
    });
    std::cout << "Records:" << std::endl;
    for (const auto& record : records){
        std::cout << record.first << std::endl;
    }
}


int main(){
    std::string filename = "sheet.txt";
    int lvl = 1;
    bool exit = true;
    std::string username;
    int game_max = 9;
    bool first_loop = true;
    while (exit){
        //std::cout << "new loop" << std::endl;
        int cheker = 1;
        int random_value;
        if (first_loop){
            random_value = randomizer(lvl, game_max);
        }
        else {
            random_value = randomizer(1, game_max);
        }
        
        int choice;
        std::cout << "Menu:\n1.Play\n2.Records\n3.Select level\n0.Exit\nCurrent level: "<< lvl << std::endl;
        std::cin >> choice;

        switch (choice){
        case 0:
            exit = false;
            break;
        case 1:
            std::cin.ignore();
            std::cout << "Please, enter your name:" << std::endl;
            std::getline(std::cin, username); //изначально было просто cin но при вводе с пробелом вселенная коллапсировала...
            while (true){
                if (number_check(random_value)){
                    std::cout << "Attempts: " << cheker << std::endl;
                    break;}
                
                cheker += 1;
                first_loop = false;
            }
            file_editing(filename, username, cheker);
            // sort_file(filename);
            // display_records(filename);
            display_sorted(filename);
            break;
        case 2:
            std::cout << "Checking records...\n";
            break;
        case 3:
            std::cout << "Please, select preferable level:\n1 - up to 10\n2 - up to 50\n3 - up to 100\n4 - set custom number" << std::endl;
            std::cin >> lvl;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;}
    }
    std::cout << "Exiting the game. Goodbye!\n";
    return 0;
}
