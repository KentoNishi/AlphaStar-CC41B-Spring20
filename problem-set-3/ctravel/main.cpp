/*
Cow Travelling
==============

Searching for the very best grass, the cows are travelling about
the pasture which is represented as a grid with N rows and M columns
(2 <= N <= 100; 2 <= M <= 100). Keen observer Farmer John has
recorded Bessie's position as (R1, C1) at a certain time and then
as (R2, C2) exactly T (0 < T <= 15) seconds later. He's not sure
if she passed through (R2, C2) before T seconds, but he knows she
is there at time T.

FJ wants a program that uses this information to calculate an integer
S that is the number of ways a cow can go from (R1, C1) to (R2, C2)
exactly in T seconds. Every second, a cow can travel from any
position to a vertically or horizontally neighboring position in
the pasture each second (no resting for the cows). Of course, the
pasture has trees through which no cow can travel.

Given a map with '.'s for open pasture space and '*' for trees,
calculate the number of possible ways to travel from (R1, C1) to
(R2, C2) in T seconds.

PROBLEM NAME: ctravel

INPUT FORMAT:

* Line 1: Three space-separated integers: N, M, and T

* Lines 2..N+1: Line i+1 describes row i of the pasture with exactly M
        characters that are each '.' or '*'

* Line N+2: Four space-separated integers: R1, C1, R2, and C2.

SAMPLE INPUT:

4 5 6
...*.
...*.
.....
.....
1 3 1 5

INPUT DETAILS:

The pasture is 4 rows by 5 colum. The cow travels from row 1, column
3 to row 1, column 5, which takes exactly 6 seconds.

OUTPUT FORMAT:

* Line 1: A single line with the integer S described above.

SAMPLE OUTPUT:

1

OUTPUT DETAILS:

There is only one way from (1,3) to (1,5) in exactly 6 seconds (and
it is the obvious one that travels around the two trees).
*/

#include <bits/stdc++.h>
using namespace std;

int N, M, T;
vector<vector<bool>> grid;
vector<vector<vector<int>>> dp;
int startR, startC, endR, endC;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int countWays(int r, int c, int t) {
    if (t == 0) {
        return r == startR && c == startC ? 1 : 0;
    }
    if (dp[r][c][t] >= 0) {
        return dp[r][c][t];
    }
    dp[r][c][t] = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= N || nr < 0 || nc >= M || nc < 0) {
            continue;
        }
        if (!grid[nr][nc]) {
            continue;
        }
        dp[r][c][t] += countWays(nr, nc, t - 1);
    }
    return dp[r][c][t];
}

int main() {
    cin >> N >> M >> T;
    grid = vector<vector<bool>>(N, vector<bool>(M));
    dp = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(T + 1, -1)));
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            grid[i][j] = str[j] == '.';
        }
    }
    cin >> startR >> startC >> endR >> endC;
    startR--;
    startC--;
    endR--;
    endC--;
    dp[startR][startC][0] = 1;
    cout << countWays(endR, endC, T) << endl;
    return 0;
}