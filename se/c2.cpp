#include <iostream>
#include <string>
#include <regex>

using namespace std;

// Function to calculate cyclomatic complexity
int calculateCyclomaticComplexity(const string &code)
{
    int complexity = 1; // Start with 1 (for the single path)

    // Regular expressions for control flow statements
    regex controlKeywords("\\b(if|else if|for|while|switch|case|&&|\\|\\|)\\b");

    // Use regex to find all control flow keywords
    auto words_begin = sregex_iterator(code.begin(), code.end(), controlKeywords);
    auto words_end = sregex_iterator();

    // Count occurrences of control flow keywords
    complexity += distance(words_begin, words_end);

    return complexity;
}

int main()
{
    // Sample C++ code as a string
    string code = R"(while (first <= last)
{
   if (array [middle] < search)
      first = middle +1;
   else if (array [middle] == search)
      found = True;
   else last = middle – 1;
   middle = (first + last)/2;
}
if (first < last) not Present = True;
)";

    // Calculate cyclomatic complexity
    int complexity = calculateCyclomaticComplexity(code);

    // Output the result
    cout << "Cyclomatic Complexity: " << complexity << endl;

    return 0;
}
