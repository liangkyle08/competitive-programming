#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
char arr[1001][1001];
vector<pair<int, int>> add = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int characterDist = 0;
int ans = 0;

void BFS(bool t) {
    vector<vector<int>> seen(N+1, vector<int>(M+1));
    queue<pair<pair<int, int>, int>> q;
    q.push({{N, M}, 0});
    while (!q.empty()) {
        int x1 = q.front().fi.fi;
        int y1 = q.front().fi.se;
        int depth = q.front().se;
        q.pop();
        if (seen[x1][y1] || arr[x1][y1] == '#') continue;
        seen[x1][y1] = true;
        if (!t && x1 == 1 && y1 == 1) {
            characterDist = depth;
        }
        if (t && arr[x1][y1] == 'M') {
            if (depth <= characterDist) {
                ans++;
            }
        }
        for (auto [xAdd, yAdd]: add) {
            int x2 = x1+xAdd;
            int y2 = y1+yAdd;
            if (1 <= x2 && x2 <= N
                && 1 <= y2 && y2 <= M) {
                q.push({{x2, y2}, depth+1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            arr[i][j] = s[j-1];
        }
    }
    BFS(false);
    BFS(true);
    cout << ans << "\n";
}
