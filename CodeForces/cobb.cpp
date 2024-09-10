#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int T, N, K;
int A[MAX_N + 5];

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    long long ans = -LL_INF;
    for (int i = 1; i <= N; i++) {
        for (int j = max(N - 2 * K, 1); j <= N; j++) {
            if (i == j) continue;
            ans = max(ans, (long long)i * (long long)j - K * (A[i] | A[j]));
        }
    }
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
