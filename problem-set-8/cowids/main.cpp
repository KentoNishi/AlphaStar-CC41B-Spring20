/*
Cow IDs
=======

Being a secret computer geek, Farmer John labels all of his cows with
binary numbers.  However, he is a bit superstitious, and only labels 
cows with binary numbers that have exactly K "1" bits (1 <= K <= 10).  
The leading bit of each label is always a "1" bit, of course.  FJ 
assigns labels in increasing numeric order, starting from the smallest 
possible valid label -- a K-bit number consisting of all "1" bits.
Unfortunately, he loses track of his labeling and needs your help: 
please determine the Nth label he should assign (1 <= N <= 10^7).

PROBLEM NAME: cowids

INPUT FORMAT:

* Line 1: Two space-separated integers, N and K.

SAMPLE INPUT:

7 3

INPUT DETAILS:

Among all binary numbers containing exactly 3 "1" bits, FJ wants 
to output the 7th in increasing sorted order.

OUTPUT FORMAT:

* Line 1: Only a single line; the binary number that is Nth in 
increasing order among the numbers with K "1" bits.

SAMPLE OUTPUT:

10110
*/

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

vector<int> num;

void nextNum() {
    int splitDigit;
    int numDigits = num.size();
    for (int i = 0; i < numDigits; i++) {
        if (numDigits - 2 - i < 0 ||
            (num[numDigits - 1 - i] == 1 &&
             num[numDigits - 2 - i] == 0)) {
            splitDigit = numDigits - i;
            break;
        }
    }
    if (splitDigit == 1) {
        num.insert(num.begin() + 1, 0);
        splitDigit++;
        numDigits++;
    } else {
        swap(num[splitDigit - 1], num[splitDigit - 2]);
    }
    int totalOnRight = 0;
    for (int i = splitDigit; i < numDigits; i++) {
        if (num[i] == 1) {
            totalOnRight++;
        }
    }
    for (int i = splitDigit; i < numDigits - totalOnRight; i++) {
        num[i] = 0;
    }
    for (int i = numDigits - totalOnRight; i < numDigits; i++) {
        num[i] = 1;
    }
}

int main() {
    int64 N, K;
    cin >> N >> K;
    if (K == 1) {
        cout << 1;
        for (int i = 0; i < N - 1; i++) {
            cout << 0;
        }
        cout << endl;
        return 0;
    }
    for (int64 i = 0; i < K; i++) {
        num.push_back(1);
    }
    for (int64 i = 0; i < N - 1; i++) {
        nextNum();
    }
    for (int i = 0; i < num.size(); i++) {
        cout << num[i];
    }
    cout << endl;
    return 0;
}