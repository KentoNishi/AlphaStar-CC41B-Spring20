/*
Mountain Watching
=================

One day, Bessie was gazing off into the distance at the beautiful
Wisconsin mountains when she wondered to herself: which mountain
is the widest one?

She decided to take N (1 <= N <= 100,000) equally-spaced height
measurements H_i (1 <= H_i <= 1,000,000,000) sequentially along the
horizon using her new Acme Long Distance Geoaltimeter.

A mountain is defined to be a consecutive sequence of H_i values
which increases (or stays the same) and then decreases (or stays
the same), e.g., 2, 3, 3, 5, 4, 4, 1. It is possible for a mountain
on the edge of her field of vision only to increase or only to
decrease in height, as well.

The width of a mountain is the number of measurements it encompasses.
Help Bessie identify the widest mountain.
Here's a simple example of a typical horizon:

           *******                   *
          *********                 ***
          **********               *****
          ***********           *********               *
*      *****************       ***********             *** *
**    *******************     *************   * *     *******      *
**********************************************************************
3211112333677777776543332111112344456765432111212111112343232111111211
aaaaaa                   ccccccccccccccccccccc eeeeeee    ggggggggg
  bbbbbbbbbbbbbbbbbbbbbbbbbbbb             ddddd ffffffffff  hhhhhhhhh

The mountains are marked 'a', 'b', etc. Obviously, mountain b is
widest with width 28. The mountain on the left has width 6 for the
purposes of this task.

PROBLEM NAME: smount

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single integer: H_i

SAMPLE INPUT:

7
3
2
3
5
4
1
6

INPUT DETAILS:

The height measurements are 3, 2, 3, 5, 4, 1, 6.

OUTPUT FORMAT:

* Line 1: A single line with a single integer that is the width of the
        widest mountain.

SAMPLE OUTPUT:

5

OUTPUT DETAILS:

The widest mountain consists of the measurements 2, 3, 5, 4, 1. Other
mountains include 3, 2 and 1, 6
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> heights = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    int left = 0;
    int ans = 0;
    while (left < N) {
        int right = left + 1;
        while (right < N && heights[right] >= heights[right - 1]) {
            right++;
        }
        int firstFlat = right;
        while (right < N && heights[right] <= heights[right - 1]) {
            if (heights[right] != heights[right - 1]) {
                firstFlat = right;
            }
            right++;
        }
        ans = max(ans, right - left);
        left = firstFlat;
    }
    cout << ans << endl;
    return 0;
}