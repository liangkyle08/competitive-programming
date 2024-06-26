#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

void solve() {
    cin >> N;
    int maxInd = 0;
    char c;
    for (int i = 0; i < N; i++) {
        cout << "? " << i << " " << i << " " << maxInd << " " << maxInd << endl;
        cin >> c;
        if (c == '>') maxInd = i;
    }
    vector<int> pos;
    pos.push_back(0);
    for (int i = 1; i < N; i++) {
        cout << "? " << i << " " << maxInd << " " << pos.back() << " " << maxInd << endl;
        cin >> c;
        if (c == '<') continue;
        if (c == '>') pos.clear();
        pos.push_back(i);
    }
    int xorInd = pos[0];
    for (int i = 0; i < (int)pos.size(); i++) {
        cout << "? " << pos[i] << " " << pos[i] << " " << xorInd << " " << xorInd << endl;
        cin >> c;
        if (c == '<') xorInd = pos[i];
    }
    cout << "! " << maxInd << " " << xorInd << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
