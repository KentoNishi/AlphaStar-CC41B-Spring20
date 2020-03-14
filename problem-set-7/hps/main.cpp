/*
Hoof, Paper, Scissors
=====================

You have probably heard of the game "Rock, Paper, Scissors". The cows 
like to play a similar game they call "Hoof, Paper, Scissors".

The rules of "Hoof, Paper, Scissors" are simple. Two cows play 
against each-other. They both count to three and then each 
simultaneously makes a gesture that represents either a hoof, a piece 
of paper, or a pair of scissors. Hoof beats scissors (since a hoof 
can smash a pair of scissors), scissors beats paper (since scissors 
can cut paper), and paper beats hoof (since the hoof can get a 
papercut). For example, if the first cow makes a "hoof" gesture and 
the second a "paper" gesture, then the second cow wins. Of course, it 
is also possible to tie, if both cows make the same gesture.

Farmer John wants to play against his prize cow, Bessie, at N games 
of "Hoof, Paper, Scissors" (1 <= N <= 100,000). Bessie, being an 
expert at the game, can predict each of FJ's gestures before he makes 
it. Unfortunately, Bessie, being a cow, is also very lazy. As a 
result, she tends to play the same gesture multiple times in a row. 
In fact, she is only willing to switch gestures at most K times over 
the entire set of games (0 <= K <= 20). For example, if K=2 , she 
might play "hoof" for the first few games, then switch to "paper" for 
a while, then finish the remaining games playing "hoof".

Given the sequence of gestures FJ will be playing, please determine 
the maximum number of games that Bessie can win.

PROBLEM NAME: hps

INPUT FORMAT:

The first line of the input file contains N and K.

The remaining N lines contains FJ's gestures, each either H, P, or S.

OUTPUT FORMAT:

Print the maximum number of games Bessie can win, given that she can 
only change gestures at most K times.

SAMPLE INPUT:

5 1
P
P
H
P
S

SAMPLE OUTPUT:

4
*/

#include <bits/stdc++.h>
using namespace std;

/*
void printTable(vector<vector<vector<int>>> &dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            for (int k = 0; k < dp[i][j].size(); k++) {
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << "++++++++++++++++" << endl;
    }
    cout << "================================" << endl;
}
*/

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> moves;
    moves.resize(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'H') {
            moves[i] = 0;
        }
        if (c == 'P') {
            moves[i] = 1;
        }
        if (c == 'S') {
            moves[i] = 2;
        }
    }
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(2, vector<vector<int>>(N + 1, vector<int>(3)));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            dp[0][i][j] = dp[0][i - 1][j] + (moves[i - 1] == j ? 1 : 0);
        }
    }
    for (int maxMoves = 1; maxMoves <= K; maxMoves++) {
        int thisIndex = maxMoves % 2;
        int previousIndex = 1 - thisIndex;
        dp[thisIndex] = vector<vector<int>>(N + 1, vector<int>(3));
        for (int game = 1; game <= N; game++) {
            for (int hand = 0; hand < 3; hand++) {
                int win = (moves[game - 1] == hand ? 1 : 0);
                dp[thisIndex][game][hand] = dp[thisIndex][game - 1][hand] + win;
                for (int other = (hand + 1) % 3; other != hand; other = (other + 1) % 3) {
                    dp[thisIndex][game][hand] = max(dp[thisIndex][game][hand], dp[previousIndex][game - 1][other] + win);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[K % 2][N][i]);
    }
    cout << ans << endl;
    return 0;
}