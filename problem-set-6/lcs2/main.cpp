/*
Longest Common Subsequence 2
============================

Given two strings s1 and s2 (0 < |s1|,|s2| <= 10000) find the size of 
their longest common subsequence. Strings can only be composed of 
lowercase and uppercase letters. A subsequence is a sequence that 
appears in the same relative order, but not necessarily contiguous. 

PROBLEM NAME: lcs2

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
    vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(d2 + 1));
    int parity = 0;
    for (int i = 1; i <= d1; i++) {
        parity = 1 - parity;
        for (int j = 1; j <= d2; j++) {
            dp[parity][j] = max(dp[parity][j - 1], dp[1 - parity][j]);
            if (s1[i] == s2[j]) {
                dp[parity][j] = max(dp[1 - parity][j - 1] + 1, dp[parity][j]);
            }
        }
    }
    cout << dp[parity][d2] << endl;
    return 0;
}