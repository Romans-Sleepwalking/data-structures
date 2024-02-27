//Romans_Prokopjevs_201RDB381

#include <iostream>
#include <string>
#include <fstream>

int MAX_NUMBERS = 50;


int main() {
    /* Solves two missing numbers from the complete list. */
    // Read the text file
    std::ifstream file("missing_2_numbers.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening the text file." << std::endl;
        return 1;
    }
    // Read the number line by line
    char ch;
    int array[MAX_NUMBERS - 2];
    int arrayIndex = 0;
    char string[3] = "\0\0";
    int stringIndex = 0;
    while (file.get(ch)) {
        if (ch == '\n' || ch == '\0') {
            if (stringIndex != 0) {
                if (stringIndex == 1) {
                    string[1] = '\0';
                }
                try {
                    int integerValue = std::stoi(string);
                    array[arrayIndex] = integerValue;
                    arrayIndex++;
                } catch(const std::exception& e) {
                    std::cerr << "Warning! " << e.what() << std::endl;
                }
            }
            stringIndex=0;
            if (ch == '\0'){
                break;
            }
        }
        else {
            string[stringIndex] = ch;
            stringIndex++;
        }
    }
    // Find the sum of all numbers and squares provided in the input
    int sum = 0;
    int sq_sum = 0;
    for (const int num : array) {
        sum += num;
        sq_sum += num * num;
    }
    // Find the expected sum of all numbers and squares provided in the input
    int expected_sum = 0;
    int expected_sq_sum = 0;
    for (int i = 1; i <= MAX_NUMBERS; i++) {
        expected_sum += i;
        expected_sq_sum += i * i;
    }
    // Find the difference
    int diff_sum = expected_sum - sum;
    int diff_sq_sum = expected_sq_sum - sq_sum;
    int diff_subs = diff_sq_sum - (diff_sum * diff_sum);
    int coef_subs = diff_sum * 2;
    std::cerr << "x + y = " << diff_sum << std::endl;
    std::cerr << "x^2 + y^2 = " << diff_sq_sum << std::endl;
    std::cerr << "2x^2 - " << coef_subs << "x + " << -diff_subs << " = 0" << std::endl;
    // Solve the quadratic equation
    int D = coef_subs * coef_subs + 8 * diff_subs;
    int x1 = -(-coef_subs + sqrt(D)) / 4;
    int x2 = -(-coef_subs - sqrt(D)) / 4;
    std::cerr << "x1 = " << x1 << "; x2 = " << x2 << std::endl;
    return 0;
}
