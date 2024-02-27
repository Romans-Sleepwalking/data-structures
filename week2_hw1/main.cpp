//Romans_Prokopjevs_201RDB381

#include <iostream>


int main() {
    /* Sort three numbers in the ascending order. */
    double num1;
    double num2;
    double num3;
    // Ask the user to prompt their three numbers
    std::cout << "Hello, please, enter the first number: ";
    std::cin >> num1;
    std::cout << "Good, please, enter the second number: ";
    std::cin >> num2;
    std::cout << "Nice, please, enter the third number: ";
    std::cin >> num3;
    // Compile and sort these three numbers ascending
    double sequence[3] = {num1, num2, num3};
    if (sequence[0] > sequence[1]) {
        double temp = sequence[0];
        sequence[0] = sequence[1];
        sequence[1] = temp;
    }
    if (sequence[1] > sequence[2]) {
        double temp = sequence[1];
        sequence[1] = sequence[2];
        sequence[2] = temp;
    }
    if (sequence[0] > sequence[1]) {
        double temp = sequence[0];
        sequence[0] = sequence[1];
        sequence[1] = temp;
    }
    std::cout << "Thanks! These numbers in the ascending order are: "
              << sequence[0] << ", "
              << sequence[1] << ", "
              << sequence[2] << "." << std::endl;
    return 0;
}
