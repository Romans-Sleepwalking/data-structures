//Romans_Prokopjevs_201RDB381

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


int main() {
    /* Find the maximal product out of the given numbers. */
    // Open the text file
    std::ifstream file("numbers_-50_50_20.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening the text file." << std::endl;
        return 1;
    }
    // Read the text file line by line compiling numbers into a vector
    std::vector<int> numbers;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            numbers.push_back(number);
        }
    }
    // Find two maximums and minimums
    int max1 = numbers[0];
    int max2 = numbers[1];
    int min1 = numbers[0];
    int min2 = numbers[1];
    for (const int num : numbers) {
        // Save two top maximum numbers
        if (num >= max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }
        // Save two bottom minimum numbers
        if (num <= min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }
    // Calculate products
    int candidate1 = min1 * min2;
    int candidate2 = max1 * max2;
    // The largest product wins
    if (candidate1 >= candidate2){
        std::cerr << candidate1 << std::endl;
    }
    else {
        std::cerr << candidate2 << std::endl;
    }
    return 0;
}
