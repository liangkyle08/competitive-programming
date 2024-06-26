#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M, K;
char H[17][17];
char V[17][17];

void solve() {
    cin >> N >> M >> K;
    int totalDist = N+M-2;
    if (K < totalDist) {
        cout << "NO\n";
        return;
    }
    if ((totalDist % 2) != (K % 2)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < M; j++) {
            if (i == 1 && (j % 2 == 0)) {
                H[i][j] = 'B';
            }
            else {
                H[i][j] = 'R';
            }
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            if (j == M) {
                if (M % 2 == 1) {
                    if (i % 2 == 0) {
                        V[i][j] = 'B';
                    }
                    else {
                        V[i][j] = 'R';
                    }
                }
                else {
                    if (i % 2 == 0) {
                        V[i][j] = 'R';
                    }
                    else {
                        V[i][j] = 'B';
                    }
                }
            }
            else {
                V[i][j] = 'R';
            }
        }
    }
    V[1][1] = 'B';
    V[1][2] = 'B';
    H[N][M-1] = V[N-1][M];
    H[N-1][M-1] = V[N-1][M];
    V[N-1][M-1] = (V[N-1][M] == 'R') ? 'B': 'R';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < M; j++) {
            cout << H[i][j] << " ";
        } cout << "\n";
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << V[i][j] << " ";
        } cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
