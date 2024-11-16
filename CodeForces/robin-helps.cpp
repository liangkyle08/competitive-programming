#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 50;

int T, N, K;
int A[MAX_N + 5];

void solve() {
    cin >> N >> K;
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] >= K) {
            cnt += A[i];
            continue;
        }
        if (cnt == 0 || A[i] > 0) continue;
        cnt--;
        ans++;
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
