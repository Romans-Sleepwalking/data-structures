//Romans_Prokopjevs_201RDB381

#include <iostream>
#include <cstring>


void printString(const char* str){
    std::cout << str << std::endl;
}

void printBoxedString(const char* str){
    /* Print text inside the star box. */
    const int boxWidth = 36;
    char res[boxWidth] = "*                                *\0";
    // Validate the string length
    int len = strlen(str);
    if (len > 30) {
        std::cout << "String size exceeds 30 characters." << std::endl;
        return;
    }
    // Add text to boxed borders
    else if (len > 0) {
        for (int i = 0; i < len; i++) {
            res[i + 2] = str[i];
        }
    }
    std::cout << res << std::endl;
}

int main() {
    /* Produce the required text output in a box. */
    const char* border = "**********************************";
    const char* blank = "";
    // Text to print
    const char* lines[] = {
    "Programming Assignment",
    "Data Structures",
    "Author: Romans Prokopjevs",
    "Due Date: January, 19"
    };
    // Print output
    printString(border);
    printBoxedString(blank);
    for (const char* text : lines) {
        printBoxedString(text);
        printBoxedString(blank);
    }
    printString(border);
    return 0;
}
