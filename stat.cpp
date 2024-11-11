#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "stat.hpp"


void Min::update(double next) {
    if (next < m_min) {
        m_min = next;
    }
}

double Min::eval() const {
    return m_min;
}

const char * Min::name() const {
    return "min";
}



void Max::update(double next) {
    if (next > m_max) {
        m_max = next;
    }
}

double Max::eval() const {
    return m_max;
}

const char * Max::name() const {
    return "max";
}


void Mean::update(double next) {
    m_sum += next;
    m_counter += 1;

}

double Mean::eval() const {
    if (m_counter == 0) return 0.0;
    return m_sum/m_counter;
}

const char * Mean::name() const {
    return "mean";
}



void Std::update(double next) {
    m_sum += next;
    list.push_back(next);
}

double Std::eval() const {
    if (list.size() == 0) return 0.0;
    double m_mean = m_sum/list.size();
    double m_mean_std = 0.0;
    for (size_t i = 0; i < list.size(); ++i){
        m_mean_std += std::pow(list[i] - m_mean, 2);
    }
    return std::sqrt(m_mean_std/list.size());
}

const char * Std::name() const {
    return "std";
}


void Pc90::update(double next) {
    list.push_back(next);
}

double Pc90::eval() const {
    if (list.empty()) {
        throw std::runtime_error("No data to calculate percentile.");
    }

    std::vector<double> sortedList = list; // 
    std::sort(sortedList.begin(), sortedList.end());

    double rank = pc_val / 100.0 * (sortedList.size() - 1);
    int lowerIndex = static_cast<int>(rank);
    double lowerValue = sortedList[lowerIndex];


    if (lowerIndex + 1 < sortedList.size()) {
        double upperValue = sortedList[lowerIndex + 1];
        return lowerValue + (rank - lowerIndex) * (upperValue - lowerValue);
    }

    return lowerValue;
}

const char* Pc90::name() const {
    return "90th percentile";
}
