//Romans_Prokopjevs_201RDB381

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>


class LineNode {
    /**
 * Linked list to store a single text line collection of any considerable size.
 */
public:
    std::string line;  // expected to be a capitalised sentence ending with new line char
    LineNode* nextLine;
    LineNode(std::string _line): line(_line), nextLine(nullptr) {}
};


class Song {
    /**
* Store a song lyrics and its metadata.
*/
private:
    std::string title;
    std::string author;
    LineNode* lyrics;
    int year;

public:
    Song(std::string _title, std::string _author, std::string _lyrics, int _year = 0) {
        /* Constructor method. */
        title = _title;
        author = _author;
        year = _year;
        // Parse lyrics into linked list
        std::stringstream ss(_lyrics);
        std::string line;
        LineNode* prevNode = nullptr;
        while (getline(ss, line, '\n')) {
            LineNode* newNode = new LineNode(line);
            if (!lyrics) {
                lyrics = newNode;
            } else {
                prevNode->nextLine = newNode;
            }
            prevNode = newNode;
        }
        std::cout << "New Song made: " << title << std::endl;
    }

    void introduce() {
        /* Print song metadata. */
        std::cout << "***\n\"" << title << "\" (" << year
                  << ") by " << author << "\n***" << std::endl;
    }

    virtual void printLine(std::string line, bool capitalise = false){
        /* Print the lyric line in the desired way. */
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

    Song& sing(int max_lines = 99999, bool capitalise = false) {
        /* Print song lyrics line by line. */
        // Tell the song name
        introduce();
        // Traverse the lyrical linked list
        LineNode* node = lyrics;
        for (int i = 0; i < max_lines; i++) {
            printLine(node->line, capitalise);
            if (node->nextLine == nullptr){
                std::cout << "***" << std::endl;
                break;
            }
            node = node->nextLine;
        }
        return *this;
    }

    Song& yell(int max_lines = 99999){
        /* Call print song method with capitalised letters (DRY). */
        return sing(max_lines, true);
    }
};
