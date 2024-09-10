#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T;
long long N, K;

long long pSum(long long X) {
    return X * (X + 1) / 2 + X * (K - 1);
}

void solve() {
    cin >> N >> K;
    long long total = pSum(N);
    long long low = 1;
    long long high = N;
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if (pSum(mid) <= total / 2) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    long long ans = min(abs(total - 2 * pSum(low)), abs(total - 2 * pSum(low + 1)));
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
