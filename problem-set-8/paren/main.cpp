/*
Best Parenthesis
================

Recently, the cows have been competing with strings of balanced
parentheses and comparing them with each other to see who has the
best one.

Such strings are scored as follows (all strings are balanced): the
string "()" has score 1; if "A" has score s(A) then "(A)" has score
2*s(A); and if "A" and "B" have scores s(A) and s(B), respectively,
then "AB" has score s(A)+s(B). For example, s("(())()") =
s("(())")+s("()") = 2*s("()")+1 = 2*1+1 = 3.

Bessie wants to beat all of her fellow cows, so she needs to calculate
the score of some strings. Given a string of balanced parentheses
of length N (2 <= N <= 100,000), help Bessie compute its score.

PROBLEM NAME: paren

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N + 1: Line i+1 will contain 1 integer: 0 if the ith
        character of the string is '(',  and 1 if the ith character of
        the string is ')'

SAMPLE INPUT:

6
0
0
1
1
0
1

INPUT DETAILS:

This corresponds to the string "(())()".

OUTPUT FORMAT:

* Line 1: The score of the string. Since this number can get quite
        large, output the  score modulo 12345678910.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

As discussed above.
*/

#include <bits/stdc++.h>
#define int64 long long
#define MOD 12345678910LL
using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> parens = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> parens[i];
    }
    vector<int64> stack = vector<int64>(N / 2 + 1);
    int64 depth = 0;
    for (int i = 0; i < N; i++) {
        int num = parens[i];
        switch (num) {
        case 0: {
            depth++;
            break;
        }
        case 1: {
            if (stack[depth] == 0) {
                stack[depth - 1]++;
            } else {
                stack[depth - 1] += stack[depth] * 2;
            }
            stack[depth - 1] %= MOD;
            stack[depth] = 0;
            depth--;
        }
        }
    }
    cout << stack[0] << endl;
    return 0;
}