#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// Function to calculate cyclomatic complexity
int calculateCyclomaticComplexity(const string& code) {
    int complexity = 1; // Start with 1 (for the single path)

    // Regular expressions for control statements that increase complexity
    regex controlKeywords("\\b(if|else if|for|while|case|catch|&&|\\|\\|)\\b");

    // Iterator for regex matches
    auto words_begin = sregex_iterator(code.begin(), code.end(), controlKeywords);
    auto words_end = sregex_iterator();

    // Count occurrences of control flow keywords
    complexity += distance(words_begin, words_end);

    return complexity;
}

int main() {
    // Read C++ code from a file
    ifstream file("code.cpp"); // Change "code.cpp" to your C++ file name
    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        return 1;
    }

    // Read the entire file content into a string
    string code((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Calculate cyclomatic complexity
    int complexity = calculateCyclomaticComplexity(code);
    cout << "Cyclomatic Complexity: " << complexity << endl;

    return 0;
}