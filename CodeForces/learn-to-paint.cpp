#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
int arr[1001][1001];

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    vector<int> DP(N+1);
    // DP[0] = {0;
    for (int i = 1; i <= N; i++) {
        DP[i] = max(DP[i], arr[1][i]);
        DP[i] = max(DP[i], DP[i-1]);
        for (int j = 1; j < i; j++) {
            for (int k = j+2; k <= i; k++) {
                DP[i] = max(DP[i], DP[j]+arr[j+2][k]);
            }
        }
        //cout << DP[i] << "\n";
    }
    cout << DP[N] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
