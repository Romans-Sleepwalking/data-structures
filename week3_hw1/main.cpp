//Romans_Prokopjevs_201RDB381

#include <iostream>


bool isPrime(int num){
    /* Decide if input is a prime number. */
    // Prime numbers are greater than 1
    if (num <= 1) {
        return false;
    }
    // Check divisibility from 2 to numbers square root
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    // If no divisors found, then it is a prime number
    return true;
}


int main() {
    /* Check if the following are prime numbers. */
    const int candidates[] = {
        1000001,
        1000021,
        1000037,
    };
    // Find if candidates are prime numbers
    for (const int num : candidates) {
        std::cerr << num << " is a prime number? Answer: "
                  << (isPrime(num) ? "true" : "false") << std::endl;
    }
    return 0;
}
