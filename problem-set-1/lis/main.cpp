/*
Longest Increasing Subsequence
==============================

Given a sequence of N numbers (0 < N <= 20,000) find the size of 
the longest increasing subsequence.

PROBLEM NAME: lis

INPUT FORMAT:

* Line 1: One integer, N

* Line 2...N+1: Numbers in the sequence

SAMPLE INPUT:

12
4
2
1
3
7
4
2
9
11
6
8
4

OUTPUT FORMAT:

* Line 1: Single integer that is the size of the longest increasing
          subsequence

SAMPLE OUTPUT:
5

OUTPUT DETAILS:

The longest increasing subsequence is 2 3 4 6 8.
1 3 4 6 8 is another one.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums;
    nums.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    vector<int> dp;
    dp.resize(N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]++;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}