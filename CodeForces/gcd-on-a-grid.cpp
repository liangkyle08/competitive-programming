#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
int A[101][101];
set<int> DP[101][101];

int GCD(int X, int Y) {
    if (X == 0) return Y;
    return GCD(Y % X, X);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) DP[i][0].insert(0);
        for (int i = 1; i <= M; i++) DP[0][i].insert(0);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> A[i][j];
                DP[i][j].clear();
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                for (auto v: DP[i][j-1]) {
                    DP[i][j].insert(GCD(A[i][j], v));
                }
                for (auto v: DP[i-1][j]) {
                    DP[i][j].insert(GCD(A[i][j], v));
                }
            }
        }
        cout << *(--DP[N][M].end()) << "\n";
    }
}
