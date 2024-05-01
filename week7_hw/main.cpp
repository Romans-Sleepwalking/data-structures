//Romans_Prokopjevs_201RDB381

#include <chrono>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>


int MIN_AGE = 1;
int MAX_AGE = 100;

struct monthType {
    std::string name;
    int numDays;
    int numLeapDays;
};

std::vector<monthType> months = {
        {"January", 31, 0},
        {"February", 28, 1},
        {"March", 31, 0},
        {"April", 30, 0},
        {"May", 31, 0},
        {"June", 30, 0},
        {"July", 31, 0},
        {"August", 31, 0},
        {"September", 30, 0},
        {"October", 31, 0},
        {"November", 30, 0},
        {"December", 31, 0},
};

class invalidYear {
public:
    invalidYear(int yearOfBirth) {
        msg = "Invalid year of birth: " + std::to_string(yearOfBirth);
    }
    std::string what() { return msg; };
private:
    std::string msg;
};

class invalidMonth {
public:
    invalidMonth(int monthOfBirth) {
        msg = "Invalid month of birth: " + std::to_string(monthOfBirth);
    }
    std::string what() { return msg; };
private:
    std::string msg;
};

class invalidDay {
public:
    invalidDay(int dayOfBirth) {
        msg = "Invalid day of birth: " + std::to_string(dayOfBirth);
    }
    std::string what() { return msg; };
private:
    std::string msg;
};


int main() {
    while (true) {
        /* Translate "dd-mm-yyyy" into "Month, ddth, yyyy". */
        std::string dateString;
        std::string stringPart;
        int dayOfBirth;
        int monthOfBirth;
        int yearOfBirth;
        // Ask system for time and find the current year
        auto now = std::chrono::system_clock::now();
        time_t time = std::chrono::system_clock::to_time_t(now);
        struct tm *parts = std::localtime(&time);
        int currentYear = parts->tm_year + 1900;
        // Ask the user to prompt their date of birth
        std::cout << "Hello, please enter your date of birth in the 'dd-mm-yyyy' format, such as \"18-11-2004\": ";
        std::cin >> dateString;
        try {
            // Parse date of birth parts
            std::istringstream iss(dateString);
            std::getline(iss, stringPart, '-');
            dayOfBirth = std::stoi(stringPart);
            std::getline(iss, stringPart, '-');
            monthOfBirth = std::stoi(stringPart);
            std::getline(iss, stringPart);
            yearOfBirth = std::stoi(stringPart);
            // Validate year. The age must be realistic.
            if (currentYear - yearOfBirth < MIN_AGE) {
                throw invalidYear(yearOfBirth);
            } else if (currentYear - yearOfBirth > MAX_AGE) {
                throw invalidYear(yearOfBirth);
            }
            // Validate month. The month should be in proper range
            if (monthOfBirth <= 0 || monthOfBirth >= 13) {
                throw invalidMonth(monthOfBirth);
            }
            // Validate day. The day should be in proper range based on the month
            int maxDays = months[monthOfBirth-1].numDays;
            if (!(yearOfBirth % 4)) {
                maxDays += months[monthOfBirth-1].numLeapDays;
            }
            if (dayOfBirth <= 0 || dayOfBirth > maxDays) {
                throw invalidDay(dayOfBirth);
            }
            std::cout << months[monthOfBirth-1].name << ", "
                      << dayOfBirth << "th, "
                      << yearOfBirth << '\n';
        }
        catch (invalidYear errObj) {
            std::cout << errObj.what() << '\n';
        }
        catch (invalidMonth errObj) {
            std::cout << errObj.what() << '\n';
        }
        catch (invalidDay errObj) {
            std::cout << errObj.what() << '\n';
        }
        catch (...) {
            std::cout << "Hmm something went wrong!\n";
        }
    }
    return 0;
}
