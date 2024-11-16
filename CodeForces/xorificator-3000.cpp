#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T;
uint64_t L, R, I, K;

uint64_t XOR(long long x) {
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}

uint64_t xor_range(long long l, long long r) {
    return XOR(r) ^ XOR(l - 1);
}

void solve() {
    cin >> L >> R >> I >> K;
    uint64_t ans = xor_range(L, R);
    ans ^= xor_range((L - K + (1 << I) - 1) >> I, (R - K) >> I) << I; // Number of bad
    ans ^= K * (((R - K) / (1 << I) - (L - K - 1) / (1 << I)) & 1); // Check if there are odd number of bad
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
