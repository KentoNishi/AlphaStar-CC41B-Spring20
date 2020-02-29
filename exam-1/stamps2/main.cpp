/*
Stamps II
=========
[Memory: 64 MB]

Given a set of N stamp values (e.g., {1 cent, 3 cents}) and an 
upper limit K to the number of stamps that can fit on an 
envelope, calculate the largest unbroken list of postages from 
1 cent to M cents that can be created.

For example, consider stamps whose values are limited to 1 cent 
and 3 cents; you can use at most 5 stamps. It's easy to see how 
to assemble postage of 1 through 5 cents (just use that many 1 
cent stamps), and successive values aren't much harder:

    6 = 3 + 3
    7 = 3 + 3 + 1
    8 = 3 + 3 + 1 + 1
    9 = 3 + 3 + 3
    10 = 3 + 3 + 3 + 1
    11 = 3 + 3 + 3 + 1 + 1
    12 = 3 + 3 + 3 + 3
    13 = 3 + 3 + 3 + 3 + 1. 

However, there is no way to make 14 cents of postage with 5 or 
fewer stamps of value 1 and 3 cents. Thus, for this set of two 
stamp values and a limit of K=5, the answer is M=13.

The most difficult test case for this problem has a time limit 
of 3 seconds.

PROGRAM NAME: stamps2

INPUT FORMAT:

* Line 1: Two integers K and N. K (1 <= K <= 200) is the total 
  number of stamps that can be used. N (1 <= N <= 15) is the 
  number of stamp values.

* Line 2: N integers, listing all of the N stamp values, each 
  of which will be at most 2000.

SAMPLE INPUT:

5 2
1 3

OUTPUT FORMAT:

Line 1:	One integer, the number of contiguous postage values 
starting at 1 cent that can be formed using no more than K 
stamps from the set.

SAMPLE OUTPUT:

13
*/

#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    cin >> K >> N;
    vector<int> stamps;
    stamps.resize(N);
    int maximum = 0;
    for (int i = 0; i < N; i++) {
        cin >> stamps[i];
        maximum = max(maximum, stamps[i]);
    }
    maximum *= K;
    vector<vector<int>> dp = vector<vector<int>>(N + 1, vector<int>(maximum + 1, K + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= maximum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j == stamps[i - 1]) {
                dp[i][j] = 1;
            }
            int index = j - stamps[i - 1];
            if (index > 0) {
                dp[i][j] = min(dp[i][j], dp[i][index] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][index] + 1);
            }
        }
    }
    /*
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= maximum; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int j = 1; j <= maximum; j++) {
        if (dp[N][j] == K + 1) {
            cout << j - 1 << endl;
            return 0;
        }
    }
    cout << maximum << endl;
    return 0;
}