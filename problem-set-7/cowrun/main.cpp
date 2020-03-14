/*
Running
=======

The cows are trying to become better athletes, so Bessie is running
on a track for exactly N (1 <= N <= 10,000) minutes. During each
minute, she can choose to either run or rest for the whole minute.

The ultimate distance Bessie runs, though, depends on her 'exhaustion
factor', which starts at 0. When she chooses to run in minute i,
she will run exactly a distance of D_i (1 <= D_i <= 1,000) and her
exhaustion factor will increase by 1 -- but must never be allowed
to exceed M (1 <= M <= 500).  If she chooses to rest, her exhaustion
factor will decrease by 1 for each minute she rests. She cannot
commence running again until her exhaustion factor reaches 0. At
that point, she can choose to run or rest.

At the end of the N minute workout, Bessie's exaustion factor must
be exactly 0, or she will not have enough energy left for the rest
of the day.

Find the maximal distance Bessie can run.

PROBLEM NAME: cowrun

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 contains the single integer: D_i

SAMPLE INPUT:

5 2
5
3
4
2
10

OUTPUT FORMAT:

* Line 1: A single integer representing the largest distance Bessie
        can run while satisfying the conditions.

SAMPLE OUTPUT:

9

OUTPUT DETAILS:

Bessie runs during the first minute (distance=5), rests during the
second minute, runs for the third (distance=4), and rests for the
fourth and fifth. Note that Bessie cannot run on the fifth minute
because she would not end with a rest factor of 0.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    vector<int> miles;
    cin >> N >> M;
    N += 1;
    miles.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> miles[i + 1];
    }
    vector<int> dp;
    dp.resize(N);
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        int total = 0;
        for (int j = 1; 2 * j + i <= N && j <= M; j++) {
            total += miles[j + i];
            dp[2 * j + i] = max(dp[2 * j + i], dp[i] + total);
        }
    }
    /*
    for (int i = 0; i < N; i++) {
        cout << dp[i] << endl;
    }
    */
    cout << dp[N - 1] << endl;
    return 0;
}