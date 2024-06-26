#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
bool arr[7][7];
bool arr2[7][7];

int parityMin(bool parity) {
    int ans = 25;
    int maxLen = 12;
    if (!parity) maxLen = 13;
    for (int len = 0; len < (1<<maxLen); len++) {
        int k = 0;
        int cnt = 0;
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                if ((i+j) % 2 == !parity) continue;
                arr2[i][j] = arr[i][j];
                if (len & (1<<k)) {
                    if (arr2[i][j]) cnt++;
                    arr2[i][j] = false;
                }
                k++;
            }
        }
        bool flag = true;
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                if ((i+j) % 2 == !parity) continue;
                if (arr2[i-1][j-1]
                    && arr2[i-1][j+1]
                    && arr2[i+1][j-1]
                    && arr2[i+1][j+1]
                    && arr2[i][j]) {
                    flag = false;
                }
            }
        }
        if (flag) {
            ans = min(ans, cnt);
        }
    }
    return ans;
}

void solve() {
    for (int i = 0; i < 7; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 7; j++) {
            arr[i][j] = (s[j] == 'B');
            arr2[i][j] = arr[i][j];
        }
    }
    cout << parityMin(0)+parityMin(1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> T;
    while (T--) {
        solve();
    }
}
