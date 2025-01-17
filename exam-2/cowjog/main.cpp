/*
Cow Jog
=======

The cows are out exercising their hooves again!  There are N cows
jogging on an infinitely-long single-lane track (1 <= N <= 100,000).
Each cow starts at a distinct position on the track, and some cows jog
at different speeds.

With only one lane in the track, cows cannot pass each other.  When a
faster cow catches up to another cow, she has to slow down to avoid
running into the other cow, becoming part of the same running group.

The cows will run for T minutes (1 <= T <= 1,000,000,000).  Please
help Farmer John determine how many groups will be left at this time.
Two cows should be considered part of the same group if they are at
the same position at the end of T minutes.

INPUT:

The first line of input contains the two integers N and T.

The following N lines each contain the initial position and speed of a
single cow.  Position is a nonnegative integer and speed is a positive
integer; both numbers are at most 1 billion.  All cows start at 
distinct positions, and these will be given in increasing order in
the input.

SAMPLE INPUT:

5 3
0 1
1 2
2 3
3 2
6 1

OUTPUT:

A single integer indicating how many groups remain after T minutes.

SAMPLE OUTPUT:

3
*/

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int main() {
    int64 N, T;
    cin >> N >> T;
    vector<pair<int64, int64>> cows;
    cows.resize(N);
    for (int64 i = 0; i < N; i++) {
        pair<int64, int64> &cow = cows[i];
        cin >> cow.first >> cow.second;
    }
    sort(cows.begin(), cows.end());
    int64 ans = 0;
    int64 minEnd = cows[N - 1].first + cows[N - 1].second * T + 1;
    for (int64 i = N - 1; i >= 0; i--) {
        int64 end = cows[i].first + cows[i].second * T;
        if (end < minEnd) {
            ans++;
            minEnd = end;
        }
    }
    cout << ans << endl;
    return 0;
}