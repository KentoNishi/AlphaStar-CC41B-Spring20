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

vector<char> num;

void nextNum() {
    int moveDigit = -1;
    int digit = 0;
    while (num.size() - digit > 0) {
        if (moveDigit == -1 && (num[num.size() - 1 - digit] == '1' && (num.size() - digit == 1 || num[num.size() - 2 - digit] == '0'))) {
            // remaining digits look like "01"
            moveDigit = digit;
        }
        digit++;
    }
    vector<char> rightPart;
    digit = 0;
    for (int i = 0; i < moveDigit; i++) {
        if (num[num.size() - 1 - digit] == '1') {
            rightPart.push_back('1');
        } else {
            rightPart.push_back('0');
        }
        digit++;
    }
    vector<char> leftPart;
    for (int i = 0; i < num.size() - digit; i++) {
        leftPart.push_back(num[i]);
    }
    if (leftPart.size() >= 2) {
        swap(leftPart[leftPart.size() - 1], leftPart[leftPart.size() - 2]);
    } else {
        leftPart.push_back('0');
    }
    /*
    cout << "Move digit: " << moveDigit << endl;
    cout << "Right part: " << rightPart << endl;
    cout << "Left part: " << leftPart << endl;
    */
    num = leftPart;
    num.insert(num.end(), rightPart.begin(), rightPart.end());
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
        num.push_back('1');
    }
    for (int64 i = 0; i < N - 1; i++) {
        nextNum();
        /*
        cout << num << endl;
        cout << "===================" << endl;
        */
    }
    for (int i = 0; i < num.size(); i++) {
        cout << num[i];
    }
    cout << endl;
    return 0;
}