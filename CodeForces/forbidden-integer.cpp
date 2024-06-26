// Educational Codeforces Round 151 (Rated for Div. 2)
// A. Forbidden Integer
// https://codeforces.com/contest/1845/problem/A


#include <bits/stdc++.h>
using namespace std;

int T, N, K, X;

void solve() {
    cin >> N >> K >> X;
    vector<int> DP(101);
    vector<int> vals[101];
    for (int i = 1; i <= K; i++) {
        if (i != X) {
            DP[i] = 1;
            vals[i].push_back(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (DP[i]) {
            for (int j = 1; j <= K; j++) {
                if (j != X && i+j <= N && !DP[i+j]) {
                    DP[i+j] = DP[i]+1;
                    vals[i+j] = vals[i];
                    vals[i+j].push_back(j);
                }
            }
        }
    }
    if (DP[N]) {
        cout << "YES\n";
        cout << DP[N] << "\n";
        for (auto v: vals[N]) {
            cout << v << " ";
        } cout << "\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
