#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;

long long factorial(long long X) {
    if (X <= 1LL) return X;
    else return (X*factorial(X-1)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<pair<int, int>> pos(K+1);
        vector<bool> seen(N+1);
        for (int i = 1; i <= K; i++) {
            cin >> pos[i].fi >> pos[i].se;
            seen[pos[i].fi] = true;
            seen[pos[i].se] = true;
        }
        long long rem = 0;
        for (int i = 1; i <= N; i++) {
            rem += !seen[i];
        }
        cout << factorial(rem) << "\n";
    }
}
