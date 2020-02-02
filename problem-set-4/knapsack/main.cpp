/*
Knapsack
========

Given a list of N (1 <= N <= 1,000) objects, each with size S_i 
(1 <= S_i <= C) and value V_i (1 <= V_i <= 1,000,000), and a 
maximum capcity C (1 <= C <= 5,000), where the sum of sizes of the 
objects used cannot exceed C, find the maximum value attainable. 
Note that there is only one of each object, so you cannot take the 
same object multiple times.

PROBLEM NAME: knapsack

INPUT FORMAT:

* Line 1: Two space-separated integers: N and C

* Line 2...N+1: Two space-separated integers: S_i and V_i

SAMPLE INPUT:

4 10
4 15
3 5
7 28
5 19

OUTPUT FORMAT: 

Only a single integer; the maximum value attainable without 
exceeding the capacity.

SAMPLE OUTPUT:

34

OUTPUT DETAILS:

Maximum value can be reached with objects 1 and 4. The total size 
is 4+5=9 (less than 10) whereas the total value is 15+19=34.
*/

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int size;
    int value;
};

int main() {
    int N, C;
    cin >> N >> C;
    vector<Item> items;
    items.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].size >> items[i].value;
    }
    vector<vector<long long>> dp = vector<vector<long long>>(N, vector<long long>(C + 1));
    for (int i = 0; i < N; i++) {
        dp[i][items[i].size] = items[i].value;
        for (int j = 0; j < C + 1; j++) {
            if (j == items[i].size) {
                continue;
            }
            long long skip = 0;
            if (i > 0) {
                skip = dp[i - 1][j];
            }
            long long use = 0;
            if (i > 0 && j - items[i].size >= 0) {
                use = dp[i - 1][j - items[i].size] + items[i].value;
            }
            dp[i][j] = max(use, skip);
        }
    }
    long long ans = 0;
    for (int i = 0; i < C + 1; i++) {
        ans = max(ans, dp[N - 1][i]);
    }
    cout << ans << endl;
    return 0;
}