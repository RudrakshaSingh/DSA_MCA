#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    int dp[100][100];

    // Initializing  base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, take the maximum from left or above
        }
    }

    return dp[n][m]; // Return the length of the Longest Common Subsequence
}

int main() {
    string s1, s2;

    cout << "Enter the first string (max 99 characters): ";
    cin >> s1;
    cout << "Enter the second string (max 99 characters): ";
    cin >> s2;

    if (s1.size() > 99 || s2.size() > 99) {
        cout << "Error: Strings cannot exceed 99 characters." << endl;
        return 1; 
    }

    cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2) << endl;

    return 0; 
}