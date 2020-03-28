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

int64 nextNum(int64 num) {
    int64 memo = num;
    int moveDigit = -1;
    int digit = 0;
    while (memo > 0) {
        if (moveDigit == -1 && (memo & 3) == 1) {
            // remaining digits look like "01"
            moveDigit = digit;
        }
        memo = memo >> 1;
        digit++;
    }
    int rightPart = 0;
    memo = num;
    for (int i = 0; i < moveDigit; i++) {
        if (memo & 1) {
            rightPart++;
        }
        rightPart = rightPart << 1;
        memo = memo >> 1;
    }
    rightPart = rightPart >> 1;
    int leftPart = memo + 1;
    /*
    cout << "Move digit: " << moveDigit << endl;
    cout << "Right part: " << rightPart << endl;
    cout << "Left part: " << leftPart << endl;
    */
    return (leftPart << moveDigit) + rightPart;
}

string binaryString(int num) {
    string str = "";
    while (num > 0) {
        str = (num & 1 ? "1" : "0") + str;
        num = num >> 1;
    }
    return str;
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
    int64 num = 0;
    for (int64 i = 0; i < K; i++) {
        num = (num << 1) + 1;
    }
    for (int64 i = 0; i < N - 1; i++) {
        num = nextNum(num);
        /*
        cout << "Step " << i + 1 << ": " << bitset<8>(num) << endl;
        cout << "================" << endl;
        */
    }
    cout << binaryString(num) << endl;
    return 0;
}