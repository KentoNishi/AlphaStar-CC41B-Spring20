/*
Selfish Grazing
===============

Each of Farmer John's N (1 <= N <= 50,000) cows likes to graze in
a certain part of the pasture, which can be thought of as a large
one-dimeensional number line. Cow i's favorite grazing range starts
at location S_i and ends at location E_i (1 <= S_i < E_i; S_i < E_i
<= 100,000,000).

Most folks know the cows are quite selfish; no cow wants to share
any of its grazing area with another. Thus, two cows i and j can
only graze at the same time if either S_i >= E_j or E_i <= S_j. FJ
would like to know the maximum number of cows that can graze at the
same time for a given set of cows and their preferences.

Consider a set of 5 cows with ranges shown below:

  ... 1    2    3    4    5    6    7    8    9   10   11   12   13 ...
  ... |----|----|----|----|----|----|----|----|----|----|----|----|----
Cow 1:      <===:===>          :              :              :
Cow 2: <========:==============:==============:=============>:
Cow 3:          :     <====>   :              :              :
Cow 4:          :              :     <========:===>          :
Cow 5:          :              :     <==>     :              :

These ranges represent (2, 4), (1, 12), (4, 5), (7, 10), and (7,
8), respectively.

For a solution, the first, third, and fourth (or fifth) cows can
all graze at the same time. If the second cow grazed, no other cows
could graze. Also, the fourth and fifth cows cannot graze together,
so it is impossible for four or more cows to graze.

PROBLEM NAME: sgraze

INPUT FORMAT:

* Line 1: A  single integer: N

* Lines 2..N+1: Line i+1 contains the two space-separated integers:
        S_i and E_i

SAMPLE INPUT:

5
2 4
1 12
4 5
7 10
7 8

OUTPUT FORMAT:

* Line 1: A single integer representing the maximum number of cows
        that can graze at once.

SAMPLE OUTPUT:

3
*/

#include <bits/stdc++.h>
using namespace std;

int N;

struct Cow {
    int left;
    int right;
};

vector<Cow> cows;

int findClosest(int i) {
    Cow cow = cows[i];
    int lower = 0;
    int upper = i;
    while (upper > lower + 1) {
        int mid = (lower + upper) / 2;
        if (cows[mid].right <= cow.left) {
            lower = mid;
        } else {
            upper = mid;
        }
    }
    if (cows[lower].right <= cow.left) {
        return lower;
    }
    return -1;
}

int main() {
    cin >> N;
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].left >> cows[i].right;
    }
    sort(cows.begin(), cows.end(), [](Cow a, Cow b) {
        return a.right < b.right;
    });
    vector<int> dp;
    dp.resize(N + 1);
    for (int i = 0; i < N; i++) {
        dp[i + 1] = max(dp[i], dp[findClosest(i) + 1] + 1);
    }
    cout << dp[N] << endl;
    return 0;
}