#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
int DP[100001][101];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int v;
        cin >> v;
        if (v > 0) {
            if (i == 1) {
                DP[i][v] = 1;
                continue;
            }
            for (int j = max(1, v-1); j <= min(M, v+1); j++) {
                DP[i][v] = (DP[i][v]+DP[i-1][j]) % MOD;
            }
        }
        else {
            if (i == 1) {
                for (int j = 1; j <= M; j++) DP[i][j] = 1;
                continue;
            }
            while (v < M) {
                v++;
                for (int j = max(1, v-1); j <= min(M, v+1); j++) {
                    DP[i][v] = (DP[i][v]+DP[i-1][j]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        ans = (ans+DP[N][i]) % MOD;
    }
    cout << ans << '\n';
}
