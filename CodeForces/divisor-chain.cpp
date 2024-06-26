#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
long long X;
long long pow2[32];

void solve() {
    cin >> X;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pow2[0] = 1LL;
    for (int i = 1; i < 32; i++) {
        pow2[i] = pow2[i-1]*2LL;
    }
    cin >> T;
    while (T--) {
        solve();
    }
}
