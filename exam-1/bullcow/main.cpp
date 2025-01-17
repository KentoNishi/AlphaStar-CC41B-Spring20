/*
Bulls and Cows
==============

Farmer John wants to position N (1 <= N <= 100,000) cows and bulls
in a single row to present at the annual fair.

FJ has observed that the bulls have been quite pugnacious lately;
if two bulls too close together in the line, they will argue and
begin to fight, ruining the presentation. Ever resourceful, FJ
calculated that any two bulls must have at least K (0 <= K < N)
cows between them in order to avoid a fight.

FJ would like you to help him by counting the number of possible
sequences of N bulls and cows that avoid any fighting. FJ considers
all bulls the to be the same and all cows to be the same; thus, two
sequences are only different if they have different kinds of cattle
in some position.

PROBLEM NAME: bullcow

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

SAMPLE INPUT:

4 2

INPUT DETAILS:

FJ wants a row of 4 cattle, but any two bulls must have at least
two cows in between them.

OUTPUT FORMAT:

* Line 1: A single integer representing the number of ways FJ could
        create such a sequence of cattle. Since this number can be
        quite large, output the result modulo 5,000,011.

SAMPLE OUTPUT:

6

OUTPUT DETAILS:

The following are the six possible sequences FJ could create (note that 'C'
stands for cow and 'B' stands for bull):
CCCC
BCCC
CBCC
CCBC
CCCB
BCCB
*/

#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    vector<vector<long long>> dp = vector<vector<long long>>(2, vector<long long>(N));
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 1; i < N; i++) {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        if (i - K >= 0) {
            dp[1][i] = dp[0][i - K];
        } else {
            dp[1][i] = 1;
        }
        dp[0][i] %= 5000011;
        dp[1][i] %= 5000011;
    }
    /*
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < N; i++) {
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
    */
    cout << (dp[0][N - 1] + dp[1][N - 1]) % 5000011 << endl;
    return 0;
}