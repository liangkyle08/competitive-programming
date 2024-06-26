#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);

int C, N, M, P;
int arr[1001][1001];
int K[1001][1001]; // Number of neighbors to become water
int D[1001][1001]; // Special Direction
int minTime[1001][1001]; // Time to become water
vector<pair<int, int>> adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// NE, SE, SW, NW
vector<pair<int, int>> diag = {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}};


void BFS() {
    queue<pair<int, int>> q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (minTime[i][j] == 0) { // Currently water
                q.push({i, j});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (minTime[i][j] == 0) continue;
            if (K[i][j] == 0) { // Can become water without any neighbors
                minTime[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int x1 = q.front().fi;
        int y1 = q.front().se;
        q.pop();
        for (auto [u, v]: adj) {
            int x2 = x1+u;
            int y2 = y1+v;
            if (x2 < 1 || x2 > N || y2 < 1 || y2 > M) continue;
            if (minTime[x2][y2] != INF) continue; // Already water
            K[x2][y2]--;
            if (K[x2][y2] <= 0) {
                minTime[x2][y2] = minTime[x1][y1]+1;
                q.push({x2, y2});
            }
        }
        for (int i = 1; i <= 4; i++) {
            int x2 = x1+diag[i-1].fi;
            int y2 = y1+diag[i-1].se;
            if (x2 < 1 || x2 > N || y2 < 1 || y2 > M) continue;
            if (minTime[x2][y2] != INF) continue; // Already water
            if (i != D[x2][y2]) continue; // Not the special direction
            K[x2][y2]--;
            if (K[x2][y2] == 0) {
                minTime[x2][y2] = minTime[x1][y1]+1;
                q.push({x2, y2});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> C >> N >> M >> P;
    for (int i = 1; i <= P; i++) {
        int x, y;
        cin >> x >> y;
        cin >> K[x][y] >> D[x][y];
        minTime[x][y] = INF;
    }
    BFS();
    if (C == 1) {
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (minTime[i][j] == 1) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    else {
        int Q;
        cin >> Q;
        while (Q--) {
            int x, y;
            cin >> x >> y;
            if (minTime[x][y] == INF) {
                cout << -1 << "\n";
                continue;
            }
            cout << minTime[x][y] << "\n";
        }
    }
}
