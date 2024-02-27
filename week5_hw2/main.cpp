//Romans_Prokopjevs_201RDB381

#include "../week5_hw1/song.cpp"

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>


class Rap : public Song {
    std::string adlib = "";
    /**
* Store a rap song that slaps.
*/
public:
    // Constructor calling the base class constructor
    Rap(std::string _title, std::string _author, std::string _lyrics, int _year = 0)
        : Song(_title, _author, _lyrics, _year) {}

    void printLine(std::string line, bool capitalise = false) override {
        /* Print the lyric line in the desired way. */
        // Put ad libs into the lyrics
        if (adlib != ""){
            std::istringstream iss(line);
            std::string word;
            std::string result;
            // Add ad lib after each word
            while (iss >> word) {
                result += word + " " + adlib + " ";
            }
            // Remove the unnessassary ad lib at the tail
            if (!result.empty()) {
                int adlibLength = adlib.length() + 1;
                result = result.substr(0, result.length() - adlibLength);
            }
            line = result;
        }
        // Show original or capitalised
        if (capitalise){
            // Iterate though each char making it upper case
            for (char c : line) {
                std::cout << static_cast<char>(std::toupper(c));
            }
            std::cout << std::endl;
        }
        else {
            std::cout << line << std::endl;
        }
    }

    Rap& break_it(int max_lines = 99999, std::string _adlib = "") {
        /* Add an uppercase drop after each word. */
        // Set state of adding ad libs to true -> the specified in one
        adlib = _adlib;
        // Make the specified ad lib uppercase
        std::transform(adlib.begin(), adlib.end(), adlib.begin(), ::toupper);
        // Print lines with the drop after each word
        sing(max_lines);
        adlib = "";
        // Set state of adding ad libs back to false
        return *this;
    }
};


int main() {
    /* Test the Rap class implementation. */
    // Define the test case
    std::string lyrics =
            "We're no strangers to love\n"
            "You know the rules and so do I (do I)\n"
            "A full commitment's what I'm thinking of\n"
            "You wouldn't get this from any other guy\n"
            "I just wanna tell you how I'm feeling\n"
            "Gotta make you understand\n"
            "\n"
            "Never gonna give you up\n"
            "Never gonna let you down\n"
            "Never gonna run around and desert you\n"
            "Never gonna make you cry\n"
            "Never gonna say goodbye\n"
            "Never gonna tell a lie and hurt you\n";
    std::string title = "Never Gonna Give You Up";
    std::string author = "Rick Astley";
    int year = 1987;
    // Initialise and call to show lyrics
    Rap* rickroll = new Rap(title, author, lyrics, year);
    // Break it should be first because singing/yelling return Song ref
    std::cout << "The ad lib is " << "yeah" << std::endl;
    rickroll->break_it(12, "yeah").sing(2).yell(3);
    return 0;
}
