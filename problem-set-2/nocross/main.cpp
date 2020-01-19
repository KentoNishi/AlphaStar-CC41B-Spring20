/*
Why Did the Cow Cross the Road II
=================================

Farmer John raises N breeds of cows (1 <= N <= 1000), conveniently 
numbered 1...N. Some pairs of breeds are friendlier than others, a 
property that turns out to be easily characterized in terms of breed 
ID: breeds a and b are friendly if |a-b| <= 4, and unfriendly 
otherwise.

A long road runs through FJ's farm. There is a sequence of N fields 
on one side of the road (one designated for each breed), and a 
sequence of N fields on the other side of the road (also one for each 
breed). To help his cows cross the road safely, FJ wants to draw 
crosswalks over the road. Each crosswalk should connect a field on 
one side of the road to a field on the other side where the two 
fields have friendly breed IDs (it is fine for the cows to wander 
into fields for other breeds, as long as they are friendly). Each 
field can be accessible via at most one crosswalk (so crosswalks 
don't meet at their endpoints).

Given the ordering of N fields on both sides of the road through FJ's 
farm, please help FJ determine the maximum number of crosswalks he 
can draw over his road, such that no two intersect.

PROBLEM NAME: nocross

INPUT FORMAT:

The first line of input contains N. The next N lines describe the 
order, by breed ID, of fields on one side of the road; each breed ID 
is an integer in the range 1...N. The last N
lines describe the order, by breed ID, of the fields on the other 
side of the road. Each breed ID appears exactly once in each ordering.

OUTPUT FORMAT:

Please output the maximum number of disjoint "friendly crosswalks" 
Farmer John can draw across the road.

SAMPLE INPUT:

6
1
2
3
4
5
6
6
5
4
3
2
1

SAMPLE OUTPUT:

5
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr1;
    arr1.resize(N);
    vector<int> arr2 = arr1;
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> arr2[i];
    }
    vector<vector<int>> dp = vector<vector<int>>(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (abs(arr1[i - 1] - arr2[j - 1]) <= 4) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[N][N] << endl;
    return 0;
}