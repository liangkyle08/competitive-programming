#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N;
int A[101][101];
bool wall[4][101][101];
bool seen[101][101];
int curSize;
int minX, maxX, minY, maxY;

void DFS(int x, int y) {
    if (x < 1 || x > N) return;
    if (y < 1 || y > N) return;
    if (seen[x][y]) return;
    seen[x][y] = true;
    curSize++;
    minX = min(minX, x);
    maxX = max(maxX, x);
    minY = min(minY, y);
    maxY = max(maxY, y);
    if (!wall[0][x][y]) {
        DFS(x, y-1);
    }
    if (!wall[1][x][y]) {
        DFS(x+1, y);
    }
    if (!wall[2][x][y]) {
        DFS(x, y+1);
    }
    if (!wall[3][x][y]) {
        DFS(x-1, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("castel.in", "r", stdin);
    freopen("castel.out", "w", stdout);
    cin >> C >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            for (int k = 0; k < 4; k++) {
                wall[k][i][j] = (A[i][j] & (1<<k));
            }
        }
    }
    int total = 0;
    int maxSize = 0;
    pair<int, int> upperLeft, lowerRight;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!seen[i][j]) {
                curSize = 0;
                minX = 101;
                maxX = 0;
                minY = 101;
                maxY = 0;
                DFS(i, j);
                if (i != 1 && j != 1) {
                    total++;
                    if (curSize > maxSize) {
                        maxSize = curSize;
                        upperLeft = {minX, minY};
                        lowerRight = {maxX, maxY};
                    }
                }
            }
        }
    }
    if (C == 1) {
        cout << total << "\n";
    }
    if (C == 2) {
        cout << maxSize << "\n";
    }
    if (C == 3) {
        cout << upperLeft.fi << " " << upperLeft.se << " " << lowerRight.fi << " " << lowerRight.se << "\n";
    }
}
