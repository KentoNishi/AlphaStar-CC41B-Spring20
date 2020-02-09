/*
String Edit Distance
====================

Given two strings s1 and s2 (0 < |s1|,|s2| <= 1000) find the minimum 
number of steps to convert s1 to s2. Valid operations are insert, 
delete or replace a character. Strings can only be composed of 
lowercase and uppercase letters.

PROBLEM NAME: sed

INPUT FORMAT:

* Line 1: s1

* Line 2: s2

SAMPLE INPUT:

SUNDAY
SATURDAY

OUTPUT FORMAT:

* Line 1: Single integer that is the minimum number of steps to
convert s1 to s2.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

The conversion steps is as follows:
0) SUNDAY
1) SAUNDAY	insert: A
2) SATUNDAY	insert: T
3) SATURDAY	replace: N => R
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int d1 = s1.size();
    int d2 = s2.size();
    vector<vector<int>> dp = vector<vector<int>>(d1 + 1, vector<int>(d2 + 1));
    for (int i = 0; i <= d1; i++) {
        for (int j = 0; j <= d2; j++) {
            dp[i][j] = INT_MAX;
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            }
            if (i > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if (i > 0 && j > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1] ? 1 : 0));
            }
        }
    }
    cout << dp[d1][d2] << endl;
    return 0;
}