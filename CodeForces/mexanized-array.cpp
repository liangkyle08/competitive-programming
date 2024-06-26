#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K, X;

void solve() {
    cin >> N >> K >> X;
    if (X < K-1) {
        cout << -1 << "\n";
        return;
    }
    if (N < K) {
        cout << -1 << "\n";
        return;
    }
    if (X == K) {
        X--;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (i < K) {
            sum += i;
        }
        else {
            sum += X;
        }
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
