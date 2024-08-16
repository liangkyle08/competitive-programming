#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T;
int N, K;
int A[MAX_N + 5];

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + N + 1);
    reverse(A + 1, A + N + 1);
    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        ans += A[i];
    }
    for (int i = 2; i <= N; i += 2) {
        ans -= A[i];
    }
    int diff = 0;
    for (int i = 2; i <= N; i += 2) {
        diff += (A[i - 1] - A[i]);
    }
    cout << ans - min(diff, K) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
