/*
Cow Pie Treasures
=================

The cows have been busily baking pies that contain gold coins! Each
pie has some number Ni (1 <= Ni <= 25) of gold coins and is neatly
labeled on its crust with the number of gold coins inside.

The cows have placed the pies very precisely in an array of R rows
and C columns (1 <= R <= C <= 100) out in the pasture.  You have
been placed in the pasture at the location (R=1,C=1) and have
gathered the gold coins in that pie. You must make your way to the
other side of the pasture, moving one column closer to the end point
(which is location (R,C)) with each move you make. As you step to
the new column, you may stay on the same row or change your row by
no more than 1 (i.e., from (r,c) you can move to (r-1,c+1), (r,
c+1), or (r+1,c+1).  Of course, you would not want to leave the
field and fail to get some gold coins, and you must end up at (R,C).

Given a map of the pasture, what is the greatest number of gold
coins you can gather?

By way of example, consider this field of gold-bearing cow pies:

start-> 6 5 3 7 9 2 7
        2 4 3 5 6 8 6
        4 9 9 9 1 5 8 <-end

Here's one path:

start-> 6 5 3 7 9 2 7
         \
        2 4 3 5 6 8 6
           \   / \
        4 9 9-9 1 5-8 <-end

The path above yields 6+4+9+9+6+5+8 = 47 gold coins. The path below
is even better and yields 50 coins, which is the best possible:

start-> 6 5 3 7 9 2 7
         \
        2 4 3 5 6-8 6
           \   /   \
        4 9 9-9 1 5 8 <-end

PROBLEM NAME: pie1

INPUT FORMAT:

* Line 1: Two space-separated integers, respectively R and C

* Lines 2..R+1: Each line contains C space-separated integers in the
        obvious order

SAMPLE INPUT:

3 7
6 5 3 7 9 2 7
2 4 3 5 6 8 6
4 9 9 9 1 5 8


OUTPUT FORMAT:

* Line 1: A single integer that is the maximum number of gold coins
        that can be gathered

SAMPLE OUTPUT:

50
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid = vector<vector<int>>(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp = grid;
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = 0;
        }
    }
    for (int c = 0; c < C - 1; c++) {
        for (int r = 0; r < R; r++) {
            int dr[] = {-1, 0, 1};
            if (dp[r][c] == 0) {
                continue;
            }
            for (int i = 0; i < 3; i++) {
                int nr = r + dr[i];
                if (nr < R && nr >= 0) {
                    dp[nr][c + 1] = max(dp[nr][c + 1], dp[r][c] + grid[nr][c + 1]);
                }
            }
        }
    }
    /*
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << dp[r][c] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[R - 1][C - 1] << endl;
    return 0;
}