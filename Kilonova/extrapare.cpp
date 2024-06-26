#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
string s;

void solve() {
    cin >> s;
    N = (int)s.size();
    int ind = N-2;
    if (K > 0) {
        while (ind >= 0 && s[ind] == '0') {
            ind -= 2;
        }
        if (ind < K) {
            s = s.substr(K, N);
        }
        else {
            s = s.substr(0, ind-K+1)+s.substr(ind+1, N);
        }
    }
    N = (int)s.size();
    for (int i = N-2; i >= 0; i -= 2) {
        if (s[i] == '1') {
            cout << -1 << "\n";
            return;
        }
    }
    ind = 0;
    while (ind < N && s[ind] == '0') ind++;
    if (ind == N) {
        cout << 0 << "\n";
        return;
    }
    else {
        for (int i = ind; i < N; i++) {
            cout << s[i];
        } cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("extrapare.in", "r", stdin);
    freopen("extrapare.out", "w", stdout);
    cin >> T >> K;
    while (T--) {
        solve();
    }
}
