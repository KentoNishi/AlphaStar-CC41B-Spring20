/*
Hay For Sale
============

Farmer John suffered a terrible loss when giant Australian cockroaches ate
the entirety of his hay inventory, leaving him with nothing to feed the
cows. He hitched up his wagon with capacity C (1 <= C <= 50,000) cubic units
and sauntered over to Farmer Don's to get some hay before the cows miss a meal.

Farmer Don had a wide variety of H (1 <= H <= 5,000) hay bales for
sale, each with its own volume (1 <= V_i <= C). Bales of hay, you
know, are somewhat flexible and can be jammed into the oddest of
spaces in a wagon.

FJ carefully evaluates the volumes so that he can figure out the
largest amount of hay he can purchase for his cows.

Given the volume constraint and a list of bales to buy, what is the
greatest volume of hay FJ can purchase?  He can't purchase partial
bales, of course.

PROBLEM NAME: hay4sale

INPUT FORMAT:

* Line 1: Two space-separated integers: C and H

* Lines 2..H+1: Each line describes the volume of a single bale: V_i

SAMPLE INPUT:

7 3
2
6
5

INPUT DETAILS:

The wagon holds 7 volumetric units; three bales are offered for sale with
volumes of 2, 6, and 5 units, respectively.

OUTPUT FORMAT:

* Line 1: A single integer which is the greatest volume of hay FJ can
        purchase given the list of bales for sale and constraints.

SAMPLE OUTPUT:

7

OUTPUT DETAILS:

Buying the two smaller bales fills the wagon.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, H;
    cin >> C >> H;
    vector<int> bales;
    bales.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> bales[i];
    }
    vector<vector<bool>> dp = vector<vector<bool>>(H, vector<bool>(C + 1));
    dp[0][0] = dp[0][bales[0]] = true;
    for (int i = 1; i < H; i++) {
        for (int j = 0; j < C + 1; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - bales[i] >= 0) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - bales[i]];
            }
        }
    }
    int i;
    for (i = C; !dp[H - 1][i];) {
        i--;
    }
    cout << i << endl;
    return 0;
}