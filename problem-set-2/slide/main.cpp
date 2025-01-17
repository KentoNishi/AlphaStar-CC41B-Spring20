/*
Water Slides
============

Inspired by the new water park at Machu Picchu in Peru, Farmer John 
has decided to build one for the cows. Its biggest attraction is to 
be a giant water slide of a peculiar design.

The superslide comprises E (1 <= E <= 150,000) mini slides connecting 
V (2 <= V <= 50,000) small pools conveniently labeled 1..V. Every mini 
slide must be traversed in its proper direction and may not be traversed 
backwards. The  cows start at pool number 1 and traverse successive 
mini slides until they end up in the pool number V, the final pool. 
Every pool (except 1, the first one) includes at least one mini slide 
entering it and (except V, the last one) at least one (different) mini 
slide exiting it.

Furthermore, a cow can reach the end of the ride (pool V) from any
pool by going down a sequence of mini slides. Finally, since this is a
slide, it is not possible to leave a pool and then encounter that pool
again after traversing some set of mini slides.

Each mini slide i runs from pool P_i to pool Q_i (1 <= P_i <= V; 1
<= Q_i <= V; P_i != Q_i) and has an associated fun value F_i (0 <=
F_i <= 2,000,000,000). Bessie's total fun for any given trip down
the superslide is the sum of the fun values of all the mini slides
traversed.

Bessie naturally wants to have as much fun as possible, given the
long time that she spends in the slide's queue waiting for the ride.
Generally, she carefully chooses which mini slide to follow out of
each pool. She is a cow, however, and no more than K (1 <= K <= 10)
times as she splashes down the slide, she loses control and follows
a random mini slide out of a pool (this can even happen on pool 1).

If Bessie chooses so as to maximize her fun in the worst case, how
much fun is she guaranteed to have for a given super-slide?

By way of example, consider a small park that has 3 pools (pool
id's shown in brackets) and four mini slides; K has the value 1
(fun values shown outside of brackets):

          [1]
         /   \
   5 -> /     \ <- 9
       /       \
     [2]---3---[3]
        \__5__/

She always starts at pool 1 and ends and pool 3. If she had her way,
she'd ride direct from pool 1 to pool 2 and then on the higher-fun
mini slide (with fun value 5) to slide 3 for a total fun value of
5+5=10. But, if she loses control at pool 1, she might slide directly
from pool 1 to pool 3 for total fun 9. If she loses control at pool
2, she could reduce her total fun to just 5+3 = 8.

Bessie wants to find the most fun she can have so she strives to
choose 1->3 for a total fun of 9. If she loses control at pool 1
and ends up on mini slide 1->2, she knows she will not lose control
at pool 2 and will end up with fun 10. Thus, she knows her minimum
fun will always be at least 9.

PROBLEM NAME: slide

INPUT FORMAT:

* Line 1: Three space separated integers: V, E, and K

* Lines 2..E + 1: Line i+1 contains three space separated integers:
        P_i, Q_i, and F_i

SAMPLE INPUT:

3 4 1
2 3 5
1 2 5
1 3 9
2 3 3

OUTPUT FORMAT:

* Line 1: A single line with a single integer that is the minimum fun
        that Bessie can guarantee she can have.

SAMPLE OUTPUT:

9
*/

#include <bits/stdc++.h>
using namespace std;

int V, E, K;

struct Edge {
    int to;
    long long fun;
};

struct Node {
    vector<Edge> edges;
};

vector<Node> graph;

vector<vector<long long>> dp;

long long funFromNode(int v, int k) {
    if (dp[v][k] >= 0) {
        return dp[v][k];
    }
    long long maxFun = 0;
    for (auto &edge : graph[v].edges) {
        maxFun = max(maxFun, edge.fun + funFromNode(edge.to, k));
    }
    long long minFun = maxFun;
    if (k > 0) {
        for (auto &edge : graph[v].edges) {
            minFun = min(minFun, edge.fun + funFromNode(edge.to, k - 1));
        }
    }
    dp[v][k] = min(minFun, maxFun);
    return dp[v][k];
}

int main() {
    cin >> V >> E >> K;
    graph.resize(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].edges.push_back({b, c});
    }
    dp = vector<vector<long long>>(V, vector<long long>(K + 1, -1));
    cout << funFromNode(0, K) << endl;
    return 0;
}