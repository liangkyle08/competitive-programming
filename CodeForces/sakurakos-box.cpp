#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
long long A[MAX_N + 5];
long long prefix[MAX_N + 5];

long long modExp(long long B, long long exp) {
    long long val = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            val = (val * B) % MOD;
        }
        B = (B * B) % MOD;
        exp /= 2;
    }
    return val;
}

void solve() {
    cin >> N;
    prefix[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        prefix[i] = (prefix[i - 1] + A[i]) % MOD;
    }
    long long ans = 0;
    for (int i = 2; i <= N; i++) {
        ans += (A[i] * prefix[i - 1]) % MOD;
        ans %= MOD;
    }
    long long div = ((long long)N * ((long long)N - 1) / 2) % MOD;
    long long invDiv = modExp(div, MOD - 2);
    ans = (ans * invDiv) % MOD;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
