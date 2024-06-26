#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int M, N;
int arr[501][501];
int addX[4] = {-1, 0, 1, 0};
int addY[4] = {0, 1, 0, -1};
int minDist[501][501];
bool seen[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            if (s[j-1] == 'X') arr[i][j] = -1;
            if (s[j-1] == 'N') arr[i][j] = 0;
            if (s[j-1] == 'E') arr[i][j] = 1;
            if (s[j-1] == 'S') arr[i][j] = 2;
            if (s[j-1] == 'W') arr[i][j] = 3;
            minDist[i][j] = (1<<30);
        }
    }
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, {1, 1}});
    while (!q.empty()) {
        int x = q.top().se.fi;
        int y = q.top().se.se;
        int val = q.top().fi;
        q.pop();
        if (x < 1 || x > M || y < 1 || y > N) continue;
        if (seen[x][y]) continue;
        seen[x][y] = true;
        minDist[x][y] = -val;
        if (arr[x][y] == -1) continue;
        for (int i = 0; i <= 3; i++) {
            int x2, y2;
            x2 = x+addX[(arr[x][y]+i) % 4];
            y2 = y+addY[(arr[x][y]+i) % 4];
            q.push({-(minDist[x][y]+i), {x2, y2}});
        }
    }
    if (minDist[M][N] == (1<<30)) minDist[M][N] = -1;
    cout << minDist[M][N] << "\n";
}
