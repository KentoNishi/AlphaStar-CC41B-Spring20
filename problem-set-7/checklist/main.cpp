/*
Cow Checklist
=============

Every day, Farmer John walks through his pasture to check on the 
well-being of each of his cows. On his farm he has two breeds of 
cows, Holsteins and Guernseys. His H Holsteins are conveniently 
numbered 1...H, and his G Guernseys are conveniently numbered 1...G 
(1 <= H <= 1000,1 <= G <= 1000). Each cow is located at a point in 
the 2D plane (not necessarily distinct).

Farmer John starts his tour at Holstein 1, and ends at Holstein H. He 
wants to visit each cow along the way, and for convenience in 
maintaining his checklist of cows visited so far, he wants to visit 
the Holsteins and Guernseys in the order in which they are numbered. 
In the sequence of all H+G cows he visits, the Holsteins numbered 1...H 
should appear as a (not necessarily contiguous) subsequence, and 
likewise for the Guernseys. Otherwise stated, the sequence of all H+G 
cows should be formed by interleaving the list of Holsteins numbered 
1...H with the list of Guernseys numbered 1...G.

When FJ moves from one cow to another cow traveling a distance of D, 
he expends D^2 energy. Please help him determine the minimum amount of 
energy required to visit all his cows according to a tour as 
described above.

PROBLEM NAME: checklist

INPUT FORMAT:

The first line of input contains H and G, separated by a space.

The next H lines contain the x and y coordinates of the H Holsteins, 
and the next G lines after that contain coordinates of the Guernseys. 
Each coordinate is an integer in the range 0...1000.

OUTPUT FORMAT:

Write a single line of output, giving the minimum energy required for 
FJ's tour of all the cows.

SAMPLE INPUT:

3 2
0 0
1 0
2 0
0 3
1 3

SAMPLE OUTPUT:

20
*/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
};

long long dist(Point &a, Point &b) {
    return (long long)pow(a.x - b.x, 2) + (long long)pow(a.y - b.y, 2);
}

int main() {
    int H, G;
    cin >> H >> G;
    vector<Point> cowsH;
    cowsH.resize(H);
    vector<Point> cowsG;
    cowsG.resize(G);
    for (int i = 0; i < H; i++) {
        Point &p = cowsH[i];
        cin >> p.x >> p.y;
    }
    for (int i = 0; i < G; i++) {
        Point &p = cowsG[i];
        cin >> p.x >> p.y;
    }
    vector<vector<vector<long long>>> dp = vector<vector<vector<long long>>>(H + 1, vector<vector<long long>>(G + 1, vector<long long>(2, 1L << 62)));
    dp[1][0][0] = 0;
    // dp[i][j][k]
    // i: next holstein index
    // j: next guernsey index
    // k: 0 = from holstein, 1 = from guernsey
    for (int h = 0; h <= H; h++) {
        for (int g = 0; g <= G; g++) {
            for (int k = 0; k < 2; k++) {
                if (k == 0 && h == 0) {
                    continue;
                }
                if (k == 1 && g == 0) {
                    continue;
                }
                Point source;
                if (k == 0) {
                    source = cowsH[h - 1];
                } else {
                    source = cowsG[g - 1];
                }
                if (h < H) {
                    dp[h + 1][g][0] = min(dp[h + 1][g][0], dp[h][g][k] + dist(cowsH[h], source));
                }
                if (g < G) {
                    dp[h][g + 1][1] = min(dp[h][g + 1][1], dp[h][g][k] + dist(cowsG[g], source));
                }
            }
        }
    }
    cout << dp[H][G][0] << endl;
    return 0;
}