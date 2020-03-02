/*
Marathon
========

Unhappy with the poor health of his cows, Farmer John enrolls them in
an assortment of different physical fitness activities.  His prize cow
Bessie is enrolled in a running class, where she is eventually
expected to run a marathon through the downtown area of the city near
Farmer John's farm!

The marathon course consists of N checkpoints (3 <= N <= 500) to be
visited in sequence, where checkpoint 1 is the starting location and
checkpoint N is the finish.  Bessie is supposed to visit all of these
checkpoints one by one, but being the lazy cow she is, she decides
that she will skip up to K checkpoints (K < N) in order to shorten her
total journey.  She cannot skip checkpoints 1 or N, however, since
that would be too noticeable.

Please help Bessie find the minimum distance that she has to run if
she can skip up to K checkpoints.  

Since the course is set in a downtown area with a grid of streets, the
distance between two checkpoints at locations (x1, y1) and (x2, y2) is
given by |x1-x2| + |y1-y2|.

PROBLEM NAME: marathon

INPUT:

The first line gives the values of N and K.

The next N lines each contain two space-separated integers, x and y,
representing a checkpoint (-1000 <= x <= 1000, -1000 <= y <= 1000).
The checkpoints are given in the order that they must be visited.
Note that the course might cross over itself several times, with
several checkpoints occurring at the same physical location.  When
Bessie skips such a checkpoint, she only skips one instance of the
checkpoint -- she does not skip every checkpoint occurring at the same
location.

SAMPLE INPUT:

5 2
0 0
8 3
1 1
10 -5
2 2

OUTPUT:

Output the minimum distance that Bessie can run by skipping up to K
checkpoints.  In the sample case shown here, skipping the checkpoints
at (8, 3) and (10, -5) leads to the minimum total distance of 4.

SAMPLE OUTPUT:

4
*/

#include <bits/stdc++.h>
using namespace std;

int N, K;

struct Point {
    int x;
    int y;
};

int dist(Point &a, Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

const int MAXIMUM = 1000001;

int main() {
    cin >> N >> K;
    vector<Point> points = vector<Point>(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    vector<vector<int>> dp = vector<vector<int>>(K + 1, vector<int>(N, MAXIMUM));
    dp[0][0] = 0;
    for (int i = 1; i < N; i++) {
        dp[0][i] = dp[0][i - 1] + dist(points[i], points[i - 1]);
    }
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j < N; j++) {
            for (int m = 0; j + 1 + m < N && i + m <= K; m++) {
                int nextI = i + m;
                int nextJ = j + m + 1;
                dp[nextI][nextJ] = min(dp[nextI][nextJ], dp[i][j] + dist(points[j], points[nextJ]));
            }
        }
    }
    cout << dp[K][N - 1] << endl;
    return 0;
}