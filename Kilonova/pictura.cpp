#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N, M;
int H[305][305];
int curPeak = 0;
bool seen[205][305][305];
int depth[305][305];
int maxDepth = 0;

void DFS(int i, int j) {
    if (seen[curPeak][i][j]) return;
    seen[curPeak][i][j] = true;
    depth[i][j]++;
    maxDepth = max(maxDepth, depth[i][j]);
    if (i > 1 && H[i][j] > H[i-1][j]) DFS(i-1, j);
    if (i < N && H[i][j] > H[i+1][j]) DFS(i+1, j);
    if (j > 1 && H[i][j] > H[i][j-1]) DFS(i, j-1);
    if (j < M && H[i][j] > H[i][j+1]) DFS(i, j+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pictura.in", "r", stdin);
    freopen("pictura.out", "w", stdout);
    cin >> C >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> H[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i > 1 && H[i][j] <= H[i-1][j]) continue;
            if (i < N && H[i][j] <= H[i+1][j]) continue;
            if (j > 1 && H[i][j] <= H[i][j-1]) continue;
            if (j < M && H[i][j] <= H[i][j+1]) continue;
            curPeak++;
            DFS(i, j);
        }
    }
    if (C == 1) {
        cout << maxDepth << "\n";
    }
}

