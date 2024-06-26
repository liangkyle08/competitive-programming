#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int MAX_N = 5e5;

int N, Q;
int A[MAX_N+1];
long long andSums[20][MAX_N+1];
long long orSums[20][MAX_N+1];
long long xorSums[20][MAX_N+1];
long long cnt[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 20; j++) {
            bool x = ((1<<j) & A[i]);
            cnt[j] += x;
            if (i == 1) continue;
            andSums[j][i] = andSums[j][i-1]+(cnt[j]*x);
            orSums[j][i] = orSums[j][i-1]+(cnt[j]);
            xorSums[j][i] = xorSums[j][i-1]+(x ? i-cnt[j] : cnt[i]);
        }
    }
    cin >> Q;
    while (Q--) {
        int t, L, R;
        cin >> t >> L >> R;
        long long ans = 0;
        if (t == 1) {
            for (int j = 0; j < 20; j++) {
                ans += (1LL<<j)*(andSums[j][R]-andSums[j][L-1]);
            }
        }
        if (t == 2) {
            for (int j = 0; j < 20; j++) {
                ans += (1LL<<j)*(xorSums[j][R]-xorSums[j][L-1]);
            }
        }
        if (t == 3) {
            for (int j = 0; j < 20; j++) {
                ans += (1LL<<j)*(orSums[j][R]-orSums[j][L-1]);
            }
        }
        cout << ans << "\n";
    }
}
