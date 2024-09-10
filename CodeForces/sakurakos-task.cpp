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
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    if (N == 1) {
        cout << K - 1 + (A[1] < K) << "\n";
        return;
    }
    int div = A[1];
    for (int i = 1; i <= N; i++) {
        div = gcd(div, A[i]);
    }
    if (div == 1) {
        cout << N + K - 1 << "\n";
        return;
    }
    if (K < div) {
        cout << K << "\n";
        return;
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (K < div) {
            ans += K;
            K = 0;
            break;
        }
        K -= div - 1;
        ans += div;
    }
    if (K > 0) ans += K;
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
