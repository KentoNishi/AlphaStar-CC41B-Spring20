/*
Cow Cash
========

The cows have not only created their own government but they have
chosen to create their own money system. In their own rebellious
way, they are curious about values of coinage. Traditionally, coins
come in values like 1, 5, 10, 20 or 25, 50, and 100 units, sometimes
with a 2 unit coin thrown in for good measure.

The cows want to know how many different ways it is possible to
dispense a certain amount of money using various coin systems. For
instance, using a system with values {1, 2, 5, 10, ...} it is
possible to create 18 units several different ways, including: 18x1,
9x2, 8x2+2x1, 3x5+2+1, and many others.

Write a program to compute how many ways to construct a given amount
of money N (1 <= N <= 10,000) using V (1 <= V <= 25) coins. It is
guaranteed that the total will fit into both a signed 'long long'
integer (C/C++), 'Int64' (Pascal), and 'long' integers in Java.

PROBLEM NAME: money

INPUT FORMAT:

* Line 1: Two space-separated integers: V and N

* Lines 2..V+1: Each line contains an integer that is an available
coin value

SAMPLE INPUT:

3 10
1
2
5


OUTPUT FORMAT:

* Line 1: A single line containing the total number of ways to
construct N money units using V coins

SAMPLE OUTPUT:

10
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, N;
    cin >> V >> N;
    vector<int> coins;
    coins.resize(V);
    for (int i = 0; i < V; i++) {
        cin >> coins[i];
    }
    vector<vector<long long>> dp = vector<vector<long long>>(V, vector<long long>(N + 1));
    for (int i = 0; i < N + 1;) {
        dp[0][i] = 1;
        i += coins[0];
    }
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < N + 1; j++) {
            long long skip = dp[i - 1][j];
            long long use = 0;
            if (j >= coins[i]) {
                use = dp[i][j - coins[i]];
            }
            dp[i][j] = use + skip;
        }
    }
    cout << dp[V - 1][N] << endl;
    return 0;
}