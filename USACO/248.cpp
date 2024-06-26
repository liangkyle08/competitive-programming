#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[249];
bool DP[249][249][301]; // At the "i" position, using previous "j" positions, value of "k";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("248.in", "r", stdin);
    //freopen("248.out", "w", stdout);
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        DP[i][1][arr[i]] = true;
        ans = max(ans, arr[i]);
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= i; j++) {
            for (int k = 300; k >= 1; k--) {
                if (DP[i][j][k])
                DP[i][j][k] =
            }
        }
    }
    cout << ans << "\n";
}
