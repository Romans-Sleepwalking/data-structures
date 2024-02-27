//Romans_Prokopjevs_201RDB381

#include <iostream>
#include <fstream>
#include <map>


int main() {
    /* Translate characters into the NATO telephony words. */
    // Read the CSV file with NATO alphabet
    const char delimiter = ',';
    std::ifstream file("nato_phonetic_alphabet.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening the CSV file." << std::endl;
        return 1;
    }
    // Read the NATO alphabet lines into a map: character -> telephony
    std::map<char, char*> natoTelephonyMap;
    char ch;
    bool readingLetter = true;
    char letter;
    char telephony[9];
    int telephonyIndex = 0;
    while (file.get(ch)) {
        if (ch == '\0'){
            break;
        }
        else if (ch == '\n'){
            readingLetter = true;
            telephony[telephonyIndex] = '\0';
            telephonyIndex = 0;
            // Copy telephony to another place in memory and pass the pointer
            char* telephonyCopy = new char[strlen(telephony) + 1];
            strcpy(telephonyCopy, telephony);
            natoTelephonyMap[letter] = telephonyCopy;
        }
        else if (ch == delimiter){
            readingLetter = false;
        }
        else {
            if (readingLetter){
                letter = ch;
            } else {
                telephony[telephonyIndex] = ch;
                telephonyIndex++;
            }
        }
    }
    while (true) {
        // Ask to input the character
        char input;
        std::cout << "Please, enter the character: ";
        std::cin >> input;
        // Access the map and respond
        auto it = natoTelephonyMap.find(input);
        if (it != natoTelephonyMap.end()) {
            std::cout << it->second << std::endl;
        } else {
            std::cout << "Not Recognized" << std::endl;
            break;
        }
    }
    return 0;
}
