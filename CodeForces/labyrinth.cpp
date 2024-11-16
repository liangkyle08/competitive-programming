#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2000;

int N, M, R, C, X, Y;
int A[MAX_N + 5][MAX_N + 5];
int seen[2][MAX_N + 5][MAX_N + 5];

void BFS(bool flag) {
    queue<array<int, 3>> q1, q2;
    q1.push({R, C, 0});
    while (!q1.empty() || !q2.empty()) {
        int x, y, cnt;
        if (q1.empty()) {
            x = q2.front()[0];
            y = q2.front()[1];
            cnt = q2.front()[2];
            q2.pop();
        }
        else {
            x = q1.front()[0];
            y = q1.front()[1];
            cnt = q1.front()[2];
            q1.pop();
        }
        if (seen[flag][x][y] || !A[x][y]) continue;
        if (cnt > (flag ? Y : X)) continue;
        seen[flag][x][y] = true;
        vector<pair<int, int>> adj = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
        for (auto [x2, y2]: adj) {
            if (x2 < 1 || x2 > N) continue;
            if (y2 < 1 || y2 > M) continue;
            if (!flag && y2 == y - 1) {
                q2.push({x2, y2, cnt + 1});
                continue;
            }
            if (flag && y2 == y + 1) {
                q2.push({x2, y2, cnt + 1});
                continue;
            }
            q1.push({x2, y2, cnt});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> R >> C >> X >> Y;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            A[i][j] = s[j - 1] == '.';
        }
    }
    BFS(0);
    BFS(1);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans += seen[0][i][j] && seen[1][i][j];
        }
    }
    cout << ans << "\n";
}
