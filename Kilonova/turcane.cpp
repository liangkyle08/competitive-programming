#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, M, N, P, Q, R;
long long DP[1001][1001];
long long row[1001][1001];
long long col[1001][1001];
long long diag[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("turcane.in", "r", stdin);
    freopen("turcane.out", "w", stdout);
    cin >> C >> N >> M >> P >> Q >> R;
    if (C == 1) { // Min Number Of Jumps
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                DP[i][j] = (1LL<<60);
            }
        }
        DP[1][1] = 0LL;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (i+j == 2) continue;
                DP[i][j] = min(DP[i][j], DP[i][j-min(j-1, P)]+1); // Horizontal;
                DP[i][j] = min(DP[i][j], DP[i-min(i-1, Q)][j]+1); // Vertical;
                DP[i][j] = min(DP[i][j], DP[i-min(min(i, j)-1, R)][j-min(min(i, j)-1, R)]+1); // Diagonal
                // Knight
                if (i > 1 && j > 2) {
                    DP[i][j] = min(DP[i][j], DP[i-1][j-2]+1);
                }
                if (i > 2 && j > 1) {
                    DP[i][j] = min(DP[i][j], DP[i-2][j-1]+1);
                }
            }
        }
        cout << DP[N][M] << "\n";
    }
    else { // Number of Possible Paths
        DP[1][1] = 1LL;
        row[1][1] = 1LL;
        col[1][1] = 1LL;
        diag[1][1] = 1LL;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (i+j == 2) continue;
                DP[i][j] = (DP[i][j]+(row[i][j-1]-row[i][j-min(j, P+1)]+MOD) % MOD) % MOD;
                DP[i][j] = (DP[i][j]+(col[i-1][j]-col[i-min(i, Q+1)][j]+MOD) % MOD) % MOD;
                DP[i][j] = (DP[i][j]+(diag[i-1][j-1]-diag[i-min(min(i, j), R+1)][j-min(min(i, j), R+1)]+MOD) % MOD) % MOD;
                if (i > 1 && j > 2) {
                    DP[i][j] = (DP[i][j]+DP[i-1][j-2]) % MOD;
                }
                if (i > 2 && j > 1) {
                    DP[i][j] = (DP[i][j]+DP[i-2][j-1]) % MOD;
                }
                row[i][j] = (row[i][j]+row[i][j-1]+DP[i][j]) % MOD;
                col[i][j] = (col[i][j]+col[i-1][j]+DP[i][j]) % MOD;
                diag[i][j] = (diag[i][j]+diag[i-1][j-1]+DP[i][j]) % MOD;
            }
        }
        cout << DP[N][M] << "\n";
    }
}
