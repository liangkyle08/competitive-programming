#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
long long N;

long long getXOR(long long X) {
    if (X % 4 == 0) {
        return X;
    }
    if (X % 4 == 1) {
        return 1;
    }
    if (X % 4 == 2) {
        return X+1;
    }
    return 0;
}

void solve() {
    cin >> N;
    long long A = 0;
    for (int i = 0; i < 32; i++) {
        if ((1LL<<i) <= N) {
            A += (1LL<<i);
        }
    }
    long long B = getXOR(N) ^ A;
    cout << A+B << "\n";
}

void debug() {
    long long ans = 0LL;
    for (int i = 0; i < (1<<N); i++) {
        long long A = 0LL;
        long long B = 0LL;
        for (int j = 0; j < N; j++) {
            if (i & (1<<j)) {
                A ^= (j+1);
            }
            else {
                B ^= (j+1);
            }
        }
        ans = max(ans, A+B);
    }
    cout << ans << '\t';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
