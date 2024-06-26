#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
string s;

void solve() {
    cin >> N >> K;
    cin >> s;
    int numOfB = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'B') {
            numOfB++;
        }
    }
    if (numOfB == K) {
        cout << 0 << "\n";
        return;
    }
    cout << 1 << "\n";
    if (numOfB > K) {
        for (int i = 0; i < N; i++) {
            if (s[i] == 'B') {
                numOfB--;
            }
            if (numOfB == K) {
                cout << i+1 << " " << 'A' << "\n";
                return;
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (s[i] == 'A') {
                numOfB++;
            }
            if (numOfB == K) {
                cout << i+1 << " " << 'B' << "\n";
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
