#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
char arr[501][501];
int minDist[501][501];
bool seen[501][501];
vector<pair<int, int>> add = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> N >> M;
    queue<pair<pair<int, int>, int>> q;
    pair<int, int> pos;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            arr[i][j] = s[j-1];
            if (arr[i][j] == '*') {
                q.push({{i, j}, 1});
            }
            if (arr[i][j] == 'S') {
                pos = {i, j};
            }
            minDist[i][j] = (1<<30);
        }
    }
    while (!q.empty()) {
        int x1 = q.front().fi.fi;
        int y1 = q.front().fi.se;
        int depth = q.front().se;
        q.pop();
        if (minDist[x1][y1] < (1<<30) || arr[x1][y1] == 'X') continue;
        if (arr[x1][y1] == 'D') continue;
        minDist[x1][y1] = depth;
        for (auto [xAdd, yAdd]: add) {
            int x2 = x1+xAdd;
            int y2 = y1+yAdd;
            if (x2 < 1 || x2 > N) continue;
            if (y2 < 1 || y2 > M) continue;
            q.push({{x2, y2}, depth+1});
        }
    }
    while (!q.empty()) q.pop();
    q.push({pos, 1});
    int ans = 0;
    while (!q.empty()) {
        int x1 = q.front().fi.fi;
        int y1 = q.front().fi.se;
        int depth = q.front().se;
        q.pop();
        if (seen[x1][y1]) continue;
        if (arr[x1][y1] == 'X') continue;
        if (arr[x1][y1] == 'D') {
            ans = depth;
            break;
        }
        if (depth >= minDist[x1][y1]) continue;
        seen[x1][y1] = true;
        for (auto [xAdd, yAdd]: add) {
            int x2 = x1+xAdd;
            int y2 = y1+yAdd;
            if (x2 < 1 || x2 > N) continue;
            if (y2 < 1 || y2 > M) continue;
            q.push({{x2, y2}, depth+1});
        }
    }
    if (ans == 0) {
        cout << "KAKTUS\n";
    }
    else {
        cout << ans-1 << "\n";
    }
}
