#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N, K;
int B[MAX_N + 5];
int C[MAX_N + 5];

void solve() {
    cin >> N >> K;
    vector<long long> cnt(K);
    for (int i = 1; i <= K; i++) {
        cin >> B[i] >> C[i];
        cnt[B[i] - 1] += C[i];
    }
    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
    long long ans = 0LL;
    for (int i = 0; i < min(N, K); i++) {
        ans += cnt[i];
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
