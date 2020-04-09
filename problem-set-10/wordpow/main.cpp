/*
Prompt
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> names = vector<string>(N);
    vector<string> goodBits = vector<string>(M);
    for (int i = 0; i < N; i++) {
        string &name = names[i];
        cin >> name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
    }
    for (int i = 0; i < M; i++) {
        string &good = goodBits[i];
        cin >> good;
        transform(good.begin(), good.end(), good.begin(), ::tolower);
    }
    for (int i = 0; i < N; i++) {
        string &name = names[i];
        int score = 0;
        for (int j = 0; j < M; j++) {
            string &good = goodBits[j];
            int goodPos = 0;
            for (int k = 0; k < name.size(); k++) {
                if (name[k] == good[goodPos]) {
                    goodPos++;
                }
                if (goodPos == good.size()) {
                    score++;
                    break;
                }
            }
        }
        cout << score << endl;
    }
    return 0;
}