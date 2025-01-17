/*
Cow Pinball II
==============

The cows are playing that cool Japanese 'pinball' game called
Pachinko. You've probably seen it, you drop a ball in the top and
it hits nails on the way down, veering just a little left or right,
until the ball comes out the bottom.

This pachinko game is special: the ball always hits the top nail
of the R rows of nails (1 <= R <= 100) and then will hit either the
right or left nail underneath that.  From there, the ball can hit
the next nail that's just a bit lower and to the left or right of
the second nail, and so on. The ball never veers too far (i.e.,
more than 1/2 nail away) from the nail it just hit.

This game also has scoring that's unique: you get points X_ij (0
<= X_ij <= 99) for each little nail you hit on the way down. The
cows want to maximize their score on this machine. What is the best
score they can achieve?

Here's an example triangle and a good route:

                    7                        *7

                  3   8                    *3   8

                8   1   0                *8   1   0

              2   7   4   4             2  *7   4   4

            4   5   2   6   5         4  *5   2   6   5

In the sample above, the route from 7 to 3 to 8 to 7 to 5 produces
the highest sum: 30. It's not possible to go from 7 to 8 to 8 --
the 8 on the third row is too far away.

PROBLEM NAME: pachinko2

INPUT FORMAT:

* Line 1: A single integer: R

* Lines 2..R+1: Line i+1 contains i space-separated integers that
        compose the scores of row R of the pachinko machine: X_i1,
        X_i2, ...

SAMPLE INPUT:

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

OUTPUT FORMAT:

* Line 1: A single integer that is the maximum achievable score.

SAMPLE OUTPUT:

30

OUTPUT DETAILS:

No other achievable sum is higher.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> nums = vector<vector<int>>(N, vector<int>(N));
    vector<vector<int>> dp = nums;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> nums[i][j];
        }
    }
    for (int level = N - 1; level > 0; level--) {
        for (int i = 0; i <= level; i++) {
            dp[level][i] += nums[level][i];
            if (i != 0) {
                dp[level - 1][i - 1] = max(dp[level - 1][i - 1], dp[level][i]);
            }
            dp[level - 1][i] = max(dp[level - 1][i], dp[level][i]);
        }
    }
    dp[0][0] += nums[0][0];
    cout << dp[0][0] << endl;
    return 0;
}