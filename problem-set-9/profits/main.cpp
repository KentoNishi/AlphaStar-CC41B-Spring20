/*
Profits
=======

The cows have opened a new business, and Farmer John wants to see
how well they are doing. The business has been running for N (1 <=
N <= 100,000) days, and every day i the cows recorded their net
profit P_i (-1,000 <= P_i <= 1,000).

Farmer John wants to find the largest total profit that the cows
have made during any consecutive time period. (Note that a consecutive
time period can range in length from one day through N days.) Help
him by writing a program to calculate the largest sum of consecutive
profits.

PROBLEM NAME: profits

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single integer: P_i

SAMPLE INPUT:

7
-3
4
9
-2
-5
8
-3

OUTPUT FORMAT:

* Line 1: A single integer representing the value of the maximum sum
        of profits for any consecutive time period.

SAMPLE OUTPUT:

14

OUTPUT DETAILS:

The maximum sum is obtained by taking the sum from the second through
the sixth number (4, 9, -2, -5, 8) => 14.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = -INT_MAX;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        sum += c;
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    cout << ans << endl;
    return 0;
}