/*
Charm Bracelet
==============

Bessie has gone to the mall's jewelry store and spies a charm
bracelet. Of course, she'd like to fill it with the best charms
possible from the N (1 <= N <= 3,402) available charms. Each charm
i in the supplied list has a weight W_i (1 <= W_i <= 400), a
'desirability' factor D_i (1 <= D_i <= 100), and can be used at
most once. Bessie can only support a charm bracelet whose weight
is no more than M (1 <= M <= 12,880).

Given that weight limit as a constraint and a list of the charms
with their weights and desirability rating, deduce the maximum
possible sum of ratings.

PROBLEM NAME: charm

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 describes charm i with two space-separated
integers: W_i and D_i

SAMPLE INPUT:

4 6
1 4
2 6
3 12
2 7

INPUT DETAILS:

Four potential charms; maximum weight 6

OUTPUT FORMAT:

* Line 1: A single integer that is the greatest sum of charm
desirabilities that can be achieved given the weight
constraints

SAMPLE OUTPUT:

23

OUTPUT DETAILS:

Without the second possible charm, the 4+12+7=23 is the highest
value for weight 1+2+3 <= 6
*/

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int size;
    int value;
};

int main() {
    int N, C;
    cin >> N >> C;
    vector<Item> items;
    items.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].size >> items[i].value;
    }
    vector<vector<long long>> dp = vector<vector<long long>>(2, vector<long long>(C + 1));
    dp[0][0] = 0;
    dp[0][items[0].size] = items[0].value;
    int parity = 0;
    for (int i = 1; i < N; i++) {
        parity = 1 - parity;
        for (int j = 0; j < C + 1; j++) {
            long long skip = 0;
            if (i > 0) {
                skip = dp[1 - parity][j];
            }
            long long use = 0;
            if (i > 0 && j - items[i].size >= 0) {
                use = dp[1 - parity][j - items[i].size] + items[i].value;
            }
            dp[parity][j] = max(use, skip);
        }
    }
    long long ans = 0;
    for (int i = 0; i < C + 1; i++) {
        ans = max(ans, dp[parity][i]);
    }
    cout << ans << endl;
    return 0;
}