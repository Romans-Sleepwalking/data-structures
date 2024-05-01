//Romans_Prokopjevs_201RDB381

#include <iostream>


int collatz_conjecture(int num, int steps = 0) {
    /* Count a number of steps required for a number to fall down to one. */
    std::cout << num << " - ";
    if (num == 1){ //
        // If number has conjected to one, then return number of steps
        std::cout << "1 (steps=" << steps << ")\n";
        return steps;
    }
    else if (num % 2){ // If odd then n*3+1
        return collatz_conjecture(num * 3 + 1, steps + 1);
    }
    // If even then n/2
    return collatz_conjecture(num / 2, steps + 1);
}


int main() {
    /* Collatz Conjecture. */
    int seed = 0;
    while (true) {
        try {
            // Ask the user to prompt their number
            std::cout << "Hello, please enter your positive integer (e.g., 871): ";
            std::cin >> seed;
            // If number is positive integer then throw invalid input error
            if (seed <= 0) {
                throw;
            }
            // Recursive function
            collatz_conjecture(seed);
        }
        catch (...) {
            std::cout << "Invalid input: " << seed << '\n';
        }
    }
}
