/*
Longest Common Substring
========================

Given two strings s1 and s2 (0 < |s1|,|s2| <= 1000) find the size of 
their longest common substring. Strings can only be composed of 
lowercase and uppercase letters. A substring is contiguous. 

PROBLEM NAME: lcs

INPUT FORMAT:

* Line 1: s1

* Line 2: s2

SAMPLE INPUT:

ACBAABAACC
CABABAADACCC

OUTPUT FORMAT:

* Line 1: Single integer that is the size of the longest common
          substring

SAMPLE OUTPUT:

4

OUTPUT DETAILS:

The longest common substring is 'ABAA'.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int d1 = s1.size();
    int d2 = s2.size();
    int ans = 0;
    vector<vector<int>> dp = vector<vector<int>>(d1, vector<int>(d2));
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            if (s1[i] == s2[j]) {
                if (i > 0 && j > 0) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                dp[i][j]++;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}