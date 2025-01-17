/*
Soda Machine
============

To meet the ever-growing demands of his N (1 <= N <= 50,000) cows,
Farmer John has bought them a new soda machine. He wants to figure
out the perfect place to install the machine.

The field in which the cows graze can be represented as a one-dimensional
number line. Cow i grazes in the range A_i..B_i (1 <= A_i <= B_i;
A_i <= B_i <= 1,000,000,000) (a range that includes its endpoints),
and FJ can place the soda machine at any integer point in the range
1..1,000,000,000.  Since cows are extremely lazy and try to move
as little as possible, each cow would like to have the soda machine
installed within her grazing range.

Sadly, it is not always possible to satisfy every cow's desires.
Thus FJ would like to know the largest number of cows that can be
satisfied.

To demonstrate the issue, consider four cows with grazing ranges
3..5, 4..8, 1..2, and 5..10; below is a schematic of their grazing
ranges:

         1   2   3   4   5   6   7   8   9  10  11  12  13
         |---|---|---|---|---|---|---|---|---|---|---|---|-...
                 aaaaaaaaa
                     bbbbbbbbbbbbbbbbb
         ccccc           ddddddddddddddddddddd

As can be seen, the first, second and fourth cows share the point 5,
but the third cow's grazing range is disjoint.  Thus, a maximum of
3 cows can have the soda machine within their grazing range.

PROBLEM NAME: soda

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains two space-separated integers: A_i
        and B_i

SAMPLE INPUT:

4
3 5
4 8
1 2
5 10

OUTPUT FORMAT:

* Line 1: A single integer representing the largest number of cows
        whose grazing intervals can all contain the soda machine.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

If the soda machine is placed at location 5, cows 1, 2, and 4 can be
satisfied. It is impossible to satisfy all four cows.
*/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int position;
    char type;
};

int main() {
    int N;
    cin >> N;
    vector<Point> line = vector<Point>(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> line[2 * i].position >> line[2 * i + 1].position;
        line[2 * i].type = 's';
        line[2 * i + 1].type = 'e';
    }
    sort(line.begin(), line.end(), [](Point &p1, Point &p2) {
        if (p1.position != p2.position) {
            return p1.position < p2.position;
        } else {
            return (p1.type - p2.type > 0);
        }
    });
    int cowCount = 0;
    int ans = 0;
    for (auto point : line) {
        if (point.type == 's') {
            cowCount++;
            ans = max(ans, cowCount);
        } else {
            cowCount--;
        }
    }
    cout << ans << endl;
    return 0;
}