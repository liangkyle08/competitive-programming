#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

void solve() {
    cin >> N;
    long long sum = 0LL;
    for (int i = 1; i <= N; i++) {
        sum += i*(2*i-1);
    }
    cout << sum << " " << 2*N << "\n";
    for (int i = N; i >= 1; i--) {
        cout << 1 << " " << i << " ";
        for (int j = 1; j <= N; j++) {
            cout << j << " ";
        } cout << "\n";
        cout << 2 << " " << i << " ";
        for (int j = 1; j <= N; j++) {
            cout << j << " ";
        } cout << "\n";
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
