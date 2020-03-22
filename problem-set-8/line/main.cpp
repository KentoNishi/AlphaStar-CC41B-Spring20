/*

Cow Line
========

The N (1 <= N <= 20) cows conveniently numbered 1...N are playing
yet another one of their crazy games with Farmer John. The cows
will arrange themselves in a line and ask Farmer John what their
line number is. In return, Farmer John can give them a line number
and the cows must rearrange themselves into that line.

A line number is assigned by numbering all the permutations of the
line in lexicographic order.

Consider this example:
Farmer John has 5 cows and gives them the line number of 3.
The permutations of the line in ascending lexicographic order:
1st: 1 2 3 4 5
2nd: 1 2 3 5 4
3rd: 1 2 4 3 5

Therefore, the cows will line themselves in the cow line 1 2 4 3 5.

The cows, in return, line themselves in the configuration "1 2 5 3 4" and 
ask Farmer John what their line number is.

Continuing with the list:
4th : 1 2 4 5 3
5th : 1 2 5 3 4

Farmer John can see the answer here is 5

Farmer John and the cows would like your help to play their game.
They have K (1 <= K <= 10,000) queries that they need help with.
Query i has two parts: C_i will be the command, which is either 'P'
or 'Q'.

If C_i is 'P', then the second part of the query will be one integer
A_i (1 <= A_i <= N!), which is a line number. This is Farmer John
challenging the cows to line up in the correct cow line.

If C_i is 'Q', then the second part of the query will be N distinct 
integers B_ij (1 <= B_ij <= N). This will denote a cow line. These are the 
cows challenging Farmer John to find their line number.

PROBLEM NAME: line

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..2*K+1: Line 2*i and 2*i+1 will contain a single query.

Line 2*i will contain just one character: 'Q' if the cows are lining
up and asking Farmer John for their line number or 'P' if Farmer
John gives the cows a line number.

If the line 2*i is 'Q', then line 2*i+1 will contain N space-separated
integers B_ij which represent the cow line. If the line 2*i is 'P',
then line 2*i+1 will contain a single integer A_i which is the line
number to solve for.

SAMPLE INPUT:

5 2
P
3
Q
1 2 5 3 4

OUTPUT FORMAT:

* Lines 1..K: Line i will contain the answer to query i.

If line 2*i of the input was 'Q', then this line will contain a
single integer, which is the line number of the cow line in line
2*i+1.

If line 2*i of the input was 'P', then this line will contain N
space separated integers giving the cow line of the number in line
2*i+1.

SAMPLE OUTPUT:

1 2 4 3 5
5
*/

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int64 N, K;

int64 findNumber(vector<int64> nums) {
    vector<int64> filled = vector<int64>(N);
    vector<int64> indexOf = filled;
    for (int i = 0; i < N; i++) {
        filled[i] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        int64 num = nums[i];
        auto iter = lower_bound(filled.begin(), filled.end(), num);
        int64 index = distance(filled.begin(), iter);
        indexOf[i] = index + 1;
        filled.erase(iter);
    }
    int64 factorial = 1;
    int64 total = 1;
    for (int64 i = 1; i < N; i++) {
        total += factorial * (indexOf[N - i - 1] - 1);
        factorial *= (i + 1);
    }
    return total;
}

vector<int64> findSequence(int64 num) {
    vector<int64> factorials = {1};
    for (int i = 1; i <= N; i++) {
        factorials.push_back(factorials[factorials.size() - 1] * i);
    }
    vector<int64> seq = vector<int64>(N);
    vector<int64> filled = vector<int64>(N);
    for (int i = 0; i < N; i++) {
        filled[i] = i + 1;
    }
    for (int pos = 0; pos < N; pos++) {
        for (int i = 1; i <= filled.size(); i++) {
            if (factorials[N - pos - 1] * (i - 1) < num &&
                factorials[N - pos - 1] * (i) >= num) {
                num -= factorials[N - pos - 1] * (i - 1);
                seq[pos] = filled[i - 1];
                filled.erase(filled.begin() + (i - 1));
                break;
            }
        }
    }
    return seq;
}

int main() {
    cin >> N >> K;
    for (int64 i = 0; i < K; i++) {
        char c;
        cin >> c;
        if (c == 'Q') {
            vector<int64> nums = vector<int64>(N);
            for (int64 j = 0; j < N; j++) {
                cin >> nums[j];
            }
            cout << findNumber(nums) << endl;
        } else if (c == 'P') {
            int64 num;
            cin >> num;
            vector<int64> nums = findSequence(num);
            for (int64 j = 0; j < N; j++) {
                cout << nums[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}