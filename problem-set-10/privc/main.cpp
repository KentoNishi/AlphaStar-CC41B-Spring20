/*
Privileged Cows
===============

Depending on their milk output, each of the N (1 <= N <= 1,000) cows is
assigned a 'privilege number' of 1, 2, or 3 that dictates whether they get
to drink water at the well earlier (privilege number 1) or later. The cows,
of course, never remember their privilege numbers until Farmer John
admonishes them.

Thus, the cows are lined up in some order and must re-align themselves so
that all the privilege number 1's are together at the front of the line,
2's follow, and 3's are together at the end of the line.

Cows, as we are so often reminded, are lazy.  What is the minimum number of
exchanges that can take place to sort the cows properly?

PROBLEM NAME: privc

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single integer that is the
        privilege number of the cow at place i in line

SAMPLE INPUT:

9
2
2
1
3
3
3
2
3
1

OUTPUT FORMAT:

* Line 1: A single integer that is the minimum number of exchanges
        required to order the cows properly

SAMPLE OUTPUT:

4

OUTPUT DETAILS:

Here is one way:
2   2   2<  1   1
2<  1   1   1   1
1<  2   2   2   2
3   3<  2   2   2 
3   3   3   3<  2
3   3   3   3   3
2   2<  3   3   3
3   3   3   3   3
1   1   1<  2<  3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> cows = vector<int>(N);
    vector<int> counts = vector<int>(3);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
        cows[i]--;
        counts[cows[i]]++;
    }
    vector<int> locations = vector<int>(4);
    locations[1] = counts[0];
    locations[2] = counts[0] + counts[1];
    locations[3] = N;
    vector<vector<int>> placements = vector<vector<int>>(3, vector<int>(3));
    // placements[i][j] = number of i in j's place
    for (int i = 0; i < 3; i++) {
        for (int j = locations[i]; j < locations[i + 1]; j++) {
            placements[cows[j]][i]++;
        }
    }
    int ans = 0;
    int doubleSwaps = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                // cout << "X ";
                continue;
            }
            int swaps = min(placements[i][j], placements[j][i]);
            ans += swaps;
            placements[i][j] -= swaps;
            placements[j][i] -= swaps;
            // cout << placements[i][j] << " ";
            doubleSwaps = max(doubleSwaps, placements[i][j]);
            doubleSwaps = max(doubleSwaps, placements[j][i]);
        }
        // cout << endl;
    }
    ans += doubleSwaps * 2;
    cout << ans << endl;
    return 0;
}