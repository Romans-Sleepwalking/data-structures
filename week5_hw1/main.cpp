//Romans_Prokopjevs_201RDB381

#include "song.cpp"

#include <string>


int main() {
    /* Test the Song class implementation. */
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
    Song* rickroll = new Song(title, author, lyrics, year);
    rickroll->yell(3).sing();
    return 0;
}