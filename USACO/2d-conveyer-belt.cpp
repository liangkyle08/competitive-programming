#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int INF = (1 << 30);

const int MAX_N = 1000;
const int MAX_Q = 2e5;

int N, Q;
int X[MAX_Q + 5];
int Y[MAX_Q + 5];
char T[MAX_Q + 5];
int dir[MAX_N + 5][MAX_N + 5];
bool good[MAX_N + 5][MAX_N + 5];
int total;
int addX[5] = {0, 0, 0, -1, 1};
int addY[5] = {0, -1, 1, 0, 0};

bool inside(int x, int y) {
    return (x >= 1 && x <= N && y >= 1 && y <= N);
}

bool isGood(int x, int y) {
    if (!inside(x, y)) return false;
    for (int i = 1; i <= 4; i++) {
       if (dir[x][y] != 0 && dir[x][y] != i) continue;
       int x2 = x + addX[i];
       int y2 = y + addY[i];
       if (!inside(x2, y2) || good[x2][y2]) return true;
    }
    return false;
}

void DFS(int x, int y) {
    if (!isGood(x, y) || good[x][y]) return;
    good[x][y] = true;
    total++;
    for (int i = 1; i <= 4; i++) {
        DFS(x + addX[i], y + addY[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> X[i] >> Y[i] >> T[i];
        if (T[i] == 'L') dir[X[i]][Y[i]] = 1;
        if (T[i] == 'R') dir[X[i]][Y[i]] = 2;
        if (T[i] == 'U') dir[X[i]][Y[i]] = 3;
        if (T[i] == 'D') dir[X[i]][Y[i]] = 4;
    }
    total = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            DFS(i, j);
        }
    }
    vector<int> ans;
    for (int i = Q; i >= 1; i--) {
        ans.push_back(N * N - total);
        dir[X[i]][Y[i]] = 0;
        DFS(X[i], Y[i]);
    }
    reverse(ans.begin(), ans.end());
    for (auto &v: ans) {
        cout << v << "\n";
    }
}
