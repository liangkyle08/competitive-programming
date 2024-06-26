#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int MAX_N = 2e5;

int T;
int N;
int A[MAX_N+1];
int cnt[2*MAX_N+1];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    long long ans = 1LL*N*(N+1LL)/2LL;
    for (int v = 0; v*v <= 2*N; v++) {
        int xorr = 0;
        cnt[0] = 1;
        for (int i = 1; i <= N; i++) {
            xorr ^= A[i];
            cnt[xorr]++;
        }
        xorr = 0;
        for (int i = 1; i <= N; i++) {
            xorr ^= A[i];
            cnt[xorr]--;
            if ((xorr ^ (v*v)) > 2*N) continue;
            ans -= cnt[xorr ^ (v*v)];
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
