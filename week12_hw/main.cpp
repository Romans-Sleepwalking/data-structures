//Romans_Prokopjevs_201RDB381

#include <fstream>
#include <iostream>
#include <vector>


using namespace std;


// Gamble
const int HASHMAP_SIZE = 700;


struct NumIdx { int num; int idx; };


struct HashMap {
    /* Minimalistic hash map for solving TwoSum. */
    vector<pair<int, int>> table;
    HashMap() { table.resize(HASHMAP_SIZE); };

    unsigned int hash(int key) {
        /* Modulo function. */
        return key % HASHMAP_SIZE;
    };

    void insert(int key, int value) {
      /* Insert key-value pair into the hashmap. */
      int index = hash(key);
      table[index] = {key, value};
    }

    pair<int, int> get(int key) {
      /* Find the value assosiated with the key. */
      int index = hash(key);
      if (table[index].first == key){
        return table[index];
      }
      return {0, 0};
    }
};


pair<int, int> twoSumHashMap(int target, vector<int> nums){
    /* An O(n) approach. */
    vector<int> res;
    HashMap nummies;
    // One loop
    int num1;
    pair<int, int> num2;
    for (int i = 0; i < nums.size(); i++) {
        num1 = nums[i];
        num2 = nummies.get(target - num1);
        // Return the complement if it does exist in the map
        if (num2.first && num2.second != i){
            return {i, num2.second};
        }
        // Otherwise, hash the solution into the map
        nummies.insert(num1, i);
     }
     return {0, 0};
};


int main(int argc, char *argv[]) {
    /* Two Sum. */
    int target;
    vector<int> nums;
    // Read file
    ifstream file("two_sum_target_n_data.txt");
    if (!file.is_open()) {
        cerr << "Error opening the input file!\n";
        return 1;
    }
    // Parse target and nums
    string line;
    int rownum = 0;
    while (getline(file, line)) {
        if (rownum == 0) {
            target = stoi(line);
        } else if (rownum > 1) {
            nums.push_back(stoi(line));
        }
        rownum++;
    }
    file.close();
    // Find indices of two numbers that sum up to the target
    pair<int, int> result = twoSumHashMap(target, nums);
    cout << "Answer: " << result.first << " and " << result.second << '\n';
    return 0;
}
