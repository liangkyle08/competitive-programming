#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int G[505][505]; // 0 means < 100, 1 means > 100, 2 means = 200
int H[505][505];
int D[505][505];
long long total = 0;

void solve(int x, int y) {
    int leftH = H[x][y];
    int leftD = D[x][y];
    for (int j = y; j <= N; j++) {
        if (!G[x][j]) break;
        leftH = min(leftH, H[x][j]);
        leftD = min(leftD, D[x][j]);
        int rightH = leftH;
        int rightD = leftD;
        for (int k = y; k >= 1; k--) {
            if (!G[x][j]) break;
            rightH = min(rightH, H[x][k]);
            rightD = min(rightD, D[x][k]);
            total += rightH*rightD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int val;
            cin >> val;
            if (val < 100) G[i][j] = 0;
            if (val > 100) G[i][j] = 1;
            if (val == 100) G[i][j] = 2;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (G[i][j]) {
                H[i][j] = 1;
                if (G[i-1][j]) {
                    H[i][j] += H[i-1][j];
                }
            }
        }
    }
    for (int i = N; i >= 0; i--) {
        for (int j = 1; j <= N; j++) {
            if (G[i][j]) {
                D[i][j] = 1;
                if (G[i+1][j]) {
                    D[i][j] += D[i+1][j];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (G[i][j] == 2) {
                solve(i, j);
                for (int k = i+1; k <= N; k++) {
                    if (H[k][j] == 0) break;
                    H[k][j] -= H[i][j];
                }
                H[i][j] = 0;
                G[i][j] = 0;
            }
        }
    }
    cout << total << "\n";
}
