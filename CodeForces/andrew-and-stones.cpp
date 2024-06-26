#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[100005];

void solve() {
    cin >> N;
    int oneCnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        oneCnt += (i > 1 && i < N) * (A[i] == 1);
    }
    if ((oneCnt == N-2) || (N == 3 && A[2] % 2 == 1)) {
        cout << -1 << "\n";
        return;
    }
    long long ans = 0;
    for (int i = 2; i < N; i++) {
        ans += (A[i] + 1) / 2;
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
