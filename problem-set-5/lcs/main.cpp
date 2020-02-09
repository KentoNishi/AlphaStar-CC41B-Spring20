/*
Longest Common Subsequence
==========================

Given two strings s1 and s2 (0 < |s1|,|s2| <= 1000) find the size of 
their longest common subsequence. Strings can only be composed of 
lowercase and uppercase letters. A subsequence is a sequence that 
appears in the same relative order, but not necessarily contiguous. 

PROBLEM NAME: lcs

INPUT FORMAT:

* Line 1: s1

* Line 2: s2

SAMPLE INPUT:

abrcadambracaaaa
tdabraccasaa

OUTPUT FORMAT:

* Line 1: Single integer that is the size of the longest common
          subsequence

SAMPLE OUTPUT:

9

OUTPUT DETAILS:

The longest common subsequence is 'dabracaaa' as shown below:

abrcadambrac a aaa
t    da braccasaa

Note that there might be different subsequences.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int d1 = s1.size();
    int d2 = s2.size();
    vector<vector<int>> dp = vector<vector<int>>(d1, vector<int>(d2));
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            if (i > 0 && j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (s1[i] == s2[j] ? 1 : 0));
            } else {
                dp[i][j] = max(dp[i][j], (s1[i] == s2[j] ? 1 : 0));
            }
            if (i > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[d1 - 1][d2 - 1] << endl;
    return 0;
}