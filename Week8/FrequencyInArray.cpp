#include <iostream>
#include<unordered_map>
using namespace std;

// function to return the characters and frequencies in the order of their occurrence
string modifyString(string &s) {
    unordered_map<char, int> d;
    string res = "";

    // Store all characters and their frequencies
    for (char i : s) {
        d[i]++;
    }

    // Build the result string with characters 
    // and their frequencies
    for (char i : s) {
        if (d[i] != 0) {
          
            // append character and frequency
            res += i + to_string(d[i]) + " "; 
          
            // mark as processed
            d[i] = 0; 
        }
    }

    return res;
}

int main() {
    string s = "ABRAKADABRA";
    cout << modifyString(s);
    return 0;
}
