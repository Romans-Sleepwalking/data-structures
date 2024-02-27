//Romans_Prokopjevs_201RDB381

#include <iostream>


int getCityYear(int p0, double perc, int delta, int p){
    /* Calculate when (if at all) the city will reach a certain population. */
    // Find if population should grow or decrease
    bool should_grow = p >= p0;
    // Find exceptions when the function changes into an opposite direction
    bool will_grow = p0 * (1 + perc / 100) + delta >= p0;
    if ((should_grow && !will_grow) || (!should_grow && will_grow)){
        return -1;
    }
    // A million years is a reasonable limit.
    for (int year = 0; year <= 1000000; year++) {
        if (p0 >= p) {
            return year;
        }
        p0 = p0 * (1 + perc / 100) + delta;
    }
    return -1;
}

struct TestCase {
    const char* input;
    int output;
};

int main() {
    /* Test if getCityYear function is correct. */
    const TestCase testCases[] = {
        {"getCityYear(1000,2,50,1200)", getCityYear(1000,2,50,1200)},
        {"getCityYear(1000, 2, -50, 5000)", getCityYear(1000, 2, -50, 5000)},
        {"getCityYear(1500, 5, 100, 5000)", getCityYear(1500, 5, 100, 5000)},
        {"getCityYear(1500000, 2.5, 10000, 2000000)", getCityYear(1500000, 2.5, 10000, 2000000)},
        {"getCityYear(1000, -3, 50, 2000)", getCityYear(1000, -3, 50, 2000)},
    };
    // Find if candidates are prime numbers
    for (const TestCase testCase: testCases) {
        std::cerr << testCase.input << " -> "
                  << testCase.output << std::endl;
    }
    return 0;
}
