//Romans_Prokopjevs_201RDB381

#include <iostream>
#include <chrono>


int main() {
    /* Tell the year of users 100 y.o. age. */
    // Ask the user for their name
    std::cout << "Please, enter your name: ";
    int nameLength = 32;
    char name[nameLength];
    std::cin.getline(name, nameLength);
    // Ask the user for their age
    std::cout << "Hey, " << name << "! Please, enter your age: ";
    int age;
    std::cin >> age;
    // Ask system for time and find the current year
    auto now = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(now);
    struct tm* parts = std::localtime(&time);
    int currentYear = parts -> tm_year + 1900;
    // Calculate the year of users 100 y.o. age
    std::cout << name
              << ", FYI, you will be 100 years old in the year of "
              << currentYear - age + 100
              << ". Bye!"
              << std::endl;
    return 0;
}
