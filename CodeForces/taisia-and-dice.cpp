#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, S, R;

void solve() {
    cin >> N >> S >> R;
    int maxA = S-R;
    vector<int> ans(N+1);
    ans[N] = maxA;
    while (R) {
        for (int i = 1; i < N; i++) {
            if (!R) break;
            ans[i]++;
            R--;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
