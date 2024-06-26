#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, A, B;
bool DP[5000001][2];

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    cin >> T >> A >> B;
    DP[0][0] = true;
    int ans = 0;
    for (int i = 0; i <= T; i++) {
        if (DP[i][0]) {
            ans = max(ans, i);
            DP[i/2][1] = true;
            if (i+A <= T) {
                DP[i+A][0] = true;
            }
            if (i+B <= T) {
                DP[i+B][0] = true;
            }
        }
    }
    for (int i = 0; i <= T; i++) {
        if (DP[i][1]) {
            ans = max(ans, i);
            if (i+A <= T) {
                DP[i+A][1] = true;
            }
            if (i+B <= T) {
                DP[i+B][1] = true;
            }
        }
    }
    cout << ans << "\n";
}
