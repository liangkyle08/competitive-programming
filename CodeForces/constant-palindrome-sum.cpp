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
int A[MAX_N + 5];

void solve() {
    cin >> N >> K;
    vector<int> cnt(2 * K + 5);
    vector<int> prefix(2 * K + 5);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N / 2; i++) {
        cnt[A[i] + A[N - i + 1]]++;
    }
    for (int i = 1; i <= N / 2; i++) {
        prefix[min(A[i], A[N - i + 1]) + 1]++;
        prefix[max(A[i], A[N - i + 1]) + K + 1]--;
    }
    for (int i = 1; i <= 2 * K + 1; i++) {
        prefix[i] += prefix[i - 1];
    }
    int ans = INF;
    for (int i = 2; i <= 2 * K; i++) {
        ans = min(ans, (prefix[i] - cnt[i]) + (N / 2 - prefix[i]) * 2);
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
