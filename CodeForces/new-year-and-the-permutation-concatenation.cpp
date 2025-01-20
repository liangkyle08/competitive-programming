#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 998244353;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e6;

int N;
long long fact[MAX_N + 5];
long long invFact[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = ((long long)i * fact[i - 1]) % MOD;
    }
    invFact[N + 1] = 1;
    for (int i = N; i >= 1; i--) {
        invFact[i] = ((long long)i * invFact[i + 1]) % MOD;
    }
    long long ans = (N * fact[N]) % MOD;
    for (int i = 2; i <= N; i++) {
        ans = (ans + MOD - invFact[i]) % MOD;
    }
    cout << ans << "\n";
}
