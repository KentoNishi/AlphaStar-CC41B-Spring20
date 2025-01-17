/*
Eating Together
===============

The cows are so very silly about their dinner partners. They have
organized themselves into three groups (conveniently numbered 1,
2, and 3) that insist upon dining together. The trouble starts when
they line up at the barn to enter the feeding area.

Each cow i carries with her a small card upon which is engraved D_i
(1 <= D_i <= 3) indicating her dining group membership. The entire
set of N (1 <= N <= 30,000) cows has lined up for dinner but it's
easy for anyone to see that they are not grouped by their dinner-partner
cards.

FJ's job is not so difficult. He just walks down the line of cows
changing their dinner partner assignment by marking out the old
number and writing in a new one. By doing so, he creates groups of
cows like 111222333 or 333222111 where the cows' dining groups are
sorted in either ascending or descending order by their dinner
cards.

FJ is just as lazy as the next fellow. He's curious: what is the
absolute mminimum number of cards he must change to create a proper
grouping of dining partners? He must only change card numbers and
must not rearrange the cows standing in line.

PROBLEM NAME: egroup

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i describes the i-th cow's current dining group
with a single integer: D_i

SAMPLE INPUT:

5
1
3
2
1
1

INPUT DETAILS:

Five cows in line: first cow and last two cows prefer dining group 1;
second cow likes group 3; third cow likes group 2.

OUTPUT FORMAT:

* Line 1: A single integer representing the minimum number of changes
that must be made so that the final sequence of cows is sorted
in either ascending or descending order

SAMPLE OUTPUT:

1

OUTPUT DETAILS:

We would need at least two changes to turn this into an increasing
sequence (changing both non-1's to a 1).

However, changing the first "1" to a "3" yields a decreasing sequence with
just one change, which is optimal.
*/

#include <bits/stdc++.h>
using namespace std;

int N;

vector<vector<int>> countInRange(vector<int> &v) {
    vector<vector<int>> dp = vector<vector<int>>(3, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            dp[j][i] = dp[j][i - 1];
            if (v[i - 1] != j + 1) {
                dp[j][i]++;
            }
        }
    }
    return dp;
}

int numSwaps(vector<int> &v) {
    vector<vector<int>> swapsInRange = countInRange(v);
    int ans = N;
    for (int r1 = 0; r1 <= N; r1++) {
        for (int r2 = r1; r2 <= N; r2++) {
            int local = 0;
            local += swapsInRange[0][r1] - swapsInRange[0][0];
            local += swapsInRange[1][r2] - swapsInRange[1][r1];
            local += swapsInRange[2][N] - swapsInRange[2][r2];
            ans = min(ans, local);
            local = 0;
            local += swapsInRange[2][r1] - swapsInRange[2][0];
            local += swapsInRange[1][r2] - swapsInRange[1][r1];
            local += swapsInRange[0][N] - swapsInRange[0][r2];
            ans = min(ans, local);
        }
    }
    return ans;
}

int main() {
    cin >> N;
    vector<int> v;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int ans = numSwaps(v);
    cout << ans << endl;
    return 0;
}