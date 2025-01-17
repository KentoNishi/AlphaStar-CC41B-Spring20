/*
Banner
======

Bessie is returning from a long trip abroad, and Farmer John wants
to erect a nice "Welcome Home" banner in her pasture for her arrival.
The banner will hang between two poles on a wire whose length is
in the range L1..L2 (1 <= L1 <= L2; L1 <= L2 <= 1,500).

The pasture's size is W x H (1 <= W <= 1,000; 1 <= H <= 1,000), and
Farmer John has installed a post at every point with integer
coordinates. Of these (W + 1) * (H + 1) points, Farmer John must
pick just two that will hold either end of the wire from which he
will hang the banner.

FJ wants no interference with his banner as it hangs and requires
that no post be directly under the tight wire he stretches between
the two chosen posts.

Farmer John needs your help to figure out how many possible ways
he can hang the banner. He knows the number is large and that a
32-bit integer might not be sufficient to compute the answer.

Consider the example pasture below, with W = 2 and H = 1:

       * * *
       * * *

The banner size is in the range 2..3. This pasture contains (2+1)
* (1+1) = 6 points and has (6 take 2) = (6*5)/(2*1) = 15 different
potential pairs of points between which the banner-holding wire
might stretch:

   (0,0)-(0,1)   (0,0)-(2,1)   (0,1)-(2,1)   (1,1)-(2,0)
   (0,0)-(1,0)   (0,1)-(1,0)   (1,0)-(1,1)   (1,1)-(2,1)
   (0,0)-(1,1)   (0,1)-(1,1)   (1,0)-(2,0)   (2,0)-(2,1)
   (0,0)-(2,0)   (0,1)-(2,0)   (1,0)-(2,1)

Of these pairs, only four have a length in the range 2..3:

                     Len                       Len
        (0,0)-(2,0) 2.00          (0,1)-(2,0) 2.24 
        (0,0)-(2,1) 2.24          (0,1)-(2,1) 2.00 

Of these four, the pairs (0,0)-(2,0) and (0,1)-(2,1) both have a
post directly on the line between the endpoints, and thus are
unsuitable.

So, just two pairs of points out of 15 are acceptable candidates for
hanging the banner wire.

PROBLEM NAME: banner

INPUT FORMAT:

* Line 1: Four space-separated integers: W, H, L1, and L2

SAMPLE INPUT:

2 1 2 3

OUTPUT FORMAT:

* Line 1: A single integer denoting the number of possible banners

SAMPLE OUTPUT:

2
*/

#include <bits/stdc++.h>
using namespace std;
#define int64 long long
int W, H, L1, L2;

bool hypComp(int i, int j) {
    double hyp = sqrt(pow(i, 2) + pow(j, 2));
    return hyp - L1 >= -1e-4 && L2 - hyp >= -1e-4;
}

int main() {
    cin >> W >> H >> L1 >> L2;
    int64 ans = 0;
    if (L1 == 1) {
        ans += H * (W + 1) + W * (H + 1);
    }
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            if (hypComp(i, j) && __gcd(i, j) == 1) {
                ans += 2LL * (W - i + 1) * (H - j + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}