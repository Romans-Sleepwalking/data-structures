//Romans_Prokopjevs_201RDB381

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>


std::pair<int, int> sum_and_count(std::vector<int> vector){
    /* Find sum and length of a given vector. */
    int sum = 0;
    int count = 0;
    for (const int num : vector) {
        sum += num;
        count++;
    }
    return std::make_pair(sum, count);
}


int main() {
    /* Run analysis over a CSV dataframe. */
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int> c;
    // Open the CSV file
    const char delimiter = ',';
    std::ifstream file("2d.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening the CSV file." << std::endl;
        return 1;
    }
    // Read the CSV file line by line
    std::string line;
    int col_order = 0;
    bool header = true;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, delimiter)) {
            if (header){
                if (col_order != 2){
                    col_order++;
                } else {
                    col_order = 0;
                    header = false;
                }
                continue;
            }
            if (col_order == 0){
                a.push_back(std::stoi(cell));
                col_order++;
            }
            else if (col_order == 1){
                b.push_back(std::stoi(cell));
                col_order++;
            }
            else {
                c.push_back(std::stoi(cell));
                col_order = 0;
            }
        }
    }
    // Find the minimal value in the vector A
    int a_min = a[0];
    for (const int num : a) {
        if (num < a_min) {
            a_min = num;
        }
    }
    // Find the average value in the vector B
    std::pair<int, int> b_sum_and_count = sum_and_count(b);
    double b_mean = double(b_sum_and_count.first) / b_sum_and_count.second;
    // Find the standard deviation in the vector C
    std::pair<int, int> c_sum_and_count = sum_and_count(c);
    float c_mean = float(c_sum_and_count.first) / c_sum_and_count.second;
    float c_variance = 0;
    for (const int num : c) {
        c_variance += pow(abs(num - c_mean), 2);
    }
    c_variance = float(c_variance) / c_sum_and_count.second;
    float c_std = sqrt(c_variance);
    // Print results
    std::cerr << "1. Minimum value in A - " << a_min << std::endl;
    std::cerr << "2. Mean average value in B - " << b_mean << std::endl;
    std::cerr << "3. Standard deviation in C - " << c_std << std::endl;
    file.close();
    return 0;
}
