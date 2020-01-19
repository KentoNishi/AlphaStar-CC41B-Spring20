/*
Cow Hopscotch
=============

Just like humans enjoy playing the game of Hopscotch, Farmer 
John's cows have invented a variant of the game for themselves 
to play. Being played by clumsy animals weighing nearly a ton, 
Cow Hopscotch almost always ends in disaster, but this has 
surprisingly not deterred the cows from attempting to play 
nearly every afternoon.

The game is played on an R by C grid (2 <= R <= 100, 2 <= C 
<= 100), where each square is labeled with an integer in the 
range 1..K (1 <= K <= R*C). Cows start in the top-left square 
and move to the bottom-right square by a sequence of jumps, 
where a jump is valid if and only if

1) You are jumping to a square labeled with a different integer 
than your current square,

2) The square that you are jumping to is at least one row below 
the current square that you are on, and

3) The square that you are jumping to is at least one column to 
the right of the current square that you are on.

Please help the cows compute the number of different possible 
sequences of valid jumps that will take them from the top-left 
square to the bottom-right square.

INPUT FORMAT:

The first line contains the integers R, C, and K. The next R 
lines will each contain C integers, each in the range 1..K.

OUTPUT FORMAT:

Output the number of different ways one can jump from the top-left 
square to the bottom-right square, mod 1000000007.

SAMPLE INPUT:

4 4 4
1 1 1 1
1 3 2 1
1 2 4 1
1 1 1 1

SAMPLE OUTPUT:

5
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> grid;
vector<vector<long long>> dp;

int main() {
    int R, C, K;
    cin >> R >> C >> K;
    grid = vector<vector<long long>>(R, vector<long long>(C));
    dp = grid;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            long long sum = 0;
            for (int a = 0; a < i; a++) {
                for (int b = 0; b < j; b++) {
                    if (grid[a][b] != grid[i][j]) {
                        sum += dp[a][b];
                        sum %= 1000000007;
                    }
                }
            }
            dp[i][j] = sum % 1000000007;
        }
    }
    cout << dp[R - 1][C - 1] % 1000000007 << endl;
    return 0;
}