#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, N, M;

void solve() {
    cin >> N >> M;
    M++;
    int ans = 0;
    for (int k = 30; k >= 0; k--) {
        if (N >= M) break;
        if ((N >> k & 1) == (M >> k & 1)) continue;
        if (M >> k & 1) {
            ans |= 1 << k;
            N |= 1 << k;
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
