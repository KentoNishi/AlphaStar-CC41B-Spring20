/*
Sand Castle
===========

Farmer John has built a sand castle! Like all good castles, the
walls have crennelations, that nifty pattern of embrasures (gaps)
and merlons (filled spaces); see the diagram below. The N (1 <= N
<= 25,000) merlons of his castle wall are conveniently numbered
1..N; merlon i has height M_i (1 <= M_i <= 100,000); his merlons
often have varying heights, unlike so many.



He wishes to modify the castle design in the following fashion: he
has a list of numbers B_1 through B_N (1 <= B_i <= 100,000), and
wants to change the merlon heights to those heights B_1, ..., B_N
in some order (not necessarily the order given or any other order
derived from the data).

To do this, he has hired some bovine craftsmen to raise and lower
the merlons' heights. Craftsmen, of course, cost a lot of money.
In particular, they charge FJ a total X (1 <= X <= 100) money per
unit height added and Y (1 <= Y <= 100) money per unit height
reduced.

FJ would like to know the cheapest possible cost of modifying his
sand castle if he picks the best permutation of heights. The answer
is guaranteed to fit within a 32-bit signed integer.

Note: about 40% of the test data will have N <= 9, and about 60% will have
N <= 18.

PROBLEM NAME: sandcas

INPUT FORMAT:

* Line 1: Three space-separated integers: N, X, and Y

* Lines 2..N+1: Line i+1 contains the two space-separated integers:
        M_i and B_i

SAMPLE INPUT:

3 6 5
3 1
1 2
1 2

INPUT DETAILS:

FJ's castle starts with heights of 3, 1, and 1. He would like to change
them so that their heights are 1, 2, and 2, in some order. It costs 6 to
add a unit of height and 5 to remove a unit of height.

OUTPUT FORMAT:

* Line 1: A single integer, the minimum cost needed to rebuild the
        castle

SAMPLE OUTPUT:

11

OUTPUT DETAILS:

FJ reduces the first merlon's height by 1, for a cost of 5 (yielding
merlons of heights 2, 1, and 1). He then adds one unit of height
to the second merlon for a cost of 6 (yielding merlons of heights
2, 2, and 1).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> before = vector<int>(N);
    vector<int> after = before;
    for (int i = 0; i < N; i++) {
        cin >> before[i] >> after[i];
    }
    sort(before.begin(), before.end());
    sort(after.begin(), after.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int difference = after[i] - before[i];
        if (difference < 0) {
            ans += Y * (-difference);
        } else {
            ans += X * difference;
        }
    }
    cout << ans << endl;
    return 0;
}