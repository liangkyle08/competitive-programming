#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

void solve() {
    cin >> N;
    long long ans = 0LL;
    for (int i = 0; i < N; i++) {
        long long cur = 0LL;
        int maxVal = 0;
        for (int j = 1; j <= N; j++) {
            if (j <= i) {
                cur += j*j;
                maxVal = max(maxVal, j*j);
            }
            else {
                cur += j*(N-j+i+1);
                maxVal = max(maxVal, j*(N-j+i+1));
            }
        }
        ans = max(ans, cur-maxVal);
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
