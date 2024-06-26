#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
string s;
array<bool, 4> path[2005][2005]; // (0) North, (1) East, (2) South, (3) West
int addX[4] = {-1, 0, 1, 0};
int addY[4] = {0, 1, 0, -1};
bool seen[2010][2010];
int MAX_X = 1005;
int MAX_Y = 1005;
int MIN_X = 1005;
int MIN_Y = 1005;

void DFS(int x, int y) {
    if (x > MAX_X || x < MIN_X) return;
    if (y > MAX_Y || y < MIN_Y) return;
    if (seen[x][y]) return;
    seen[x][y] = true;
    for (int i = 0; i < 4; i++) {
        if (path[x][y][i]) continue;
        DFS(x+addX[i], y+addY[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    cin >> N >> s;
    int x = 1005;
    int y = 1005;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'N') {
            x--;
            path[x][y][3] = true;
            path[x][y-1][1] = true;
        }
        if (s[i] == 'S') {
            path[x][y][3] = true;
            path[x][y-1][1] = true;
            x++;
        }
        if (s[i] == 'E') {
            path[x][y][0] = true;
            path[x-1][y][2] = true;
            y++;
        }
        if (s[i] == 'W') {
            y--;
            path[x][y][0] = true;
            path[x-1][y][2] = true;
        }
        MAX_X = max(x, MAX_X);
        MAX_Y = max(y, MAX_Y);
        MIN_X = min(x-1, MIN_X);
        MIN_Y = min(y-1, MIN_Y);
    }
    MAX_X++;
    MAX_Y++;
    MIN_X--;
    MIN_Y--;
    int comps = 0;
    for (int i = MIN_X ; i <= MAX_X; i++) {
        for (int j = MIN_Y; j <= MAX_Y; j++) {
            if (!seen[i][j]) {
                DFS(i, j);
                comps++;
            }
        }
    }
    cout << comps-1 << "\n";
}
