//Romans_Prokopjevs_201RDB381

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>


using namespace std;


const int UTF_8_SIZE = 1000000;


/* InputParser <——— COPY FROM STACKOVERFLOW:
 * https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
 */
class InputParser{
public:
    InputParser (int &argc, char **argv){
        for (int i=1; i < argc; ++i)
            this->tokens.push_back(string(argv[i]));
    }
    /// @author iain
    const string& getCmdOption(const string &option) const{
        vector<string>::const_iterator itr;
        itr =  find(this->tokens.begin(), this->tokens.end(), option);
        if (itr != this->tokens.end() && ++itr != this->tokens.end()){
            return *itr;
        }
        static const string empty_string("");
        return empty_string;
    }
    /// @author iain
    bool cmdOptionExists(const string &option) const{
        return find(this->tokens.begin(), this->tokens.end(), option)
               != this->tokens.end();
    }
private:
    vector <string> tokens;
};


struct SymbolFreq {
    wchar_t symbol;
    int count;
    SymbolFreq(wchar_t symbol, int count) : symbol(symbol), count(count) {}
};


bool compareByCount(const SymbolFreq& a, const SymbolFreq& b) {
    /* Pick higher frequency for descending sorting. */
    return a.count > b.count;
}


int main(int argc, char *argv[]) {
    /* Symbol counter. */
    vector<SymbolFreq> resVector;
    string inputFilename = "text.txt";
    bool convertLowercase = false;
    InputParser input(argc, argv);
    try {
        // Open the file
        if (input.cmdOptionExists("-i")){
            inputFilename = input.getCmdOption("-i");
        }
        wifstream inFile(inputFilename);
        if (!inFile.is_open()) {
            throw invalid_argument("error opening the input file!");
        }
        // Read output filename
        string outputFilename = inputFilename.substr(
                0, inputFilename.length() - 3
        ) + "csv";
        if (input.cmdOptionExists("-o")){
            outputFilename = input.getCmdOption("-o");
        }
        // Do lowercase?
        if (input.cmdOptionExists("-l")){
            convertLowercase = true;
        }
        cout << "Lowercase: " << (convertLowercase ? "yes" : "no") << ".\n";
        // Create a counting array of zeros representing the UTF-8 alphabet
        vector<unsigned int> symbolCounter(UTF_8_SIZE, 0);
        // Read the file char by char and count occurrences
        wchar_t wc;
        while (inFile.get(wc)) {
            // Count each character using its numeric value slot
            if (convertLowercase){
                wc = towlower(wc);
            }
            symbolCounter[wc]++;
        }
        inFile.close();
        // Create a vector of symbols with positive frequencies
        for (size_t i = 0; i < UTF_8_SIZE; ++i){
            if (symbolCounter[i]){
                resVector.push_back({
                    static_cast<wchar_t>(i),
                    static_cast<int>(symbolCounter[i])
                });
            }
        }
        // Sort the result vector descending
        sort(resVector.begin(), resVector.end(), compareByCount);
        // Save frequencies as TSV
        wofstream outFile(outputFilename);
        if (!outFile.is_open()) {
            throw invalid_argument("error opening the output file!");
        }
        outFile << L"symbol" << L'\t' << L"count" << L'\n';
        for (const SymbolFreq row : resVector) {
            outFile << row.symbol << L'\t' << row.count << L'\n';
        }
        outFile.close();
    }
    catch (const invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << '\n';
    }
    return 0;
}
