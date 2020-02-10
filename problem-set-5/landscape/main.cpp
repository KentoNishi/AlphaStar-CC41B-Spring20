/*
Landscaping
===========

Farmer John is building a nicely-landscaped garden, and needs to move a
large amount of dirt in the process.

The garden consists of a sequence of N flowerbeds (1 <= N <= 100), where
flowerbed i initially contains A_i units of dirt.  Farmer John would like
to re-landscape the garden so that each flowerbed i instead contains B_i
units of dirt.  The A_i's and B_i's are all integers in the range 0..10.

To landscape the garden, Farmer John has several options: he can purchase
one unit of dirt and place it in a flowerbed of his choice for $X.  He can
remove one unit of dirt from a flowerbed of his choice and have it shipped
away for $Y.  He can also transport one unit of dirt from flowerbed i to
flowerbed j at a cost of $Z times |i-j|.  Please compute the minimum total
cost for Farmer John to complete his landscaping project.

PROBLEM NAME: landscape

INPUT FORMAT:

* Line 1: Space-separated integers N, X, Y, and Z (0 <= X, Y, Z <=
        1000).

* Lines 2..1+N: Line i+1 contains the space-separated integers A_i and
        B_i.

SAMPLE INPUT:

4 100 200 1
1 4
2 3
3 2
4 0

INPUT DETAILS:

There are 4 flowerbeds in a row, initially with 1, 2, 3, and 4 units of
dirt. Farmer John wishes to transform them so they have 4, 3, 2, and 0
units of dirt, respectively.  The costs for adding, removing, and
transporting dirt are 100, 200, and 1.

OUTPUT FORMAT:

* Line 1: A single integer giving the minimum cost for Farmer John's
        landscaping project.

SAMPLE OUTPUT:

210

OUTPUT DETAILS:

One unit of dirt must be removed (from flowerbed #4), at a cost of 200.  The
remaining dirt can be moved at a cost of 10 (3 units from flowerbed #4 to
flowerbed #1, 1 unit from flowerbed #3 to flowerbed #2).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<int> before;
    vector<int> after;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < a; j++) {
            before.push_back(i);
        }
        for (int j = 0; j < b; j++) {
            after.push_back(i);
        }
    }
    int d1 = before.size();
    int d2 = after.size();
    vector<vector<int>> dp = vector<vector<int>>(d1 + 1, vector<int>(d2 + 1));
    for (int i = 0; i < d1; i++) {
        dp[i + 1][0] = dp[i][0] + Y;
    }
    for (int j = 0; j < d2; j++) {
        dp[0][j + 1] = dp[0][j] + X;
    }
    for (int i = 1; i <= d1; i++) {
        for (int j = 1; j <= d2; j++) {
            dp[i][j] = INT_MAX;
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + Y);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + X);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + Z * abs(before[i - 1] - after[j - 1]));
        }
    }
    cout << dp[d1][d2] << endl;
    return 0;
}