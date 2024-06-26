#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
vector<vector<bool>> A;
vector<vector<int>> cnc;
vector<int> sz;
int cur;
vector<pair<int, int>> adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void DFS(int x, int y) {
    if (!A[x][y]) return;
    if (cnc[x][y]) return;
    cnc[x][y] = cur;
    sz[cur]++;
    for (auto [xAdd, yAdd]: adj) {
        if (x+xAdd < 1 || x+xAdd > N) continue;
        if (y+yAdd < 1 || y+yAdd > M) continue;
        DFS(x+xAdd, y+yAdd);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        A.clear();
        A.resize(N+1);
        cnc.clear();
        cnc.resize(N+1);
        sz.clear();
        sz.push_back(0);
        for (int i = 1; i <= N; i++) {
            A[i].resize(M+1);
            cnc[i].resize(M+1);
        }
        for (int i = 1; i <= N; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= M; j++) {
                if (s[j-1] == '#') {
                    A[i][j] = true;
                }
            }
        }
        cur = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (!A[i][j]) continue;
                if (cnc[i][j]) continue;
                cur++;
                sz.push_back(0);
                DFS(i, j);
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            int cnt = 0;
            vector<bool> seen(cur+1);
            for (int j = 1; j <= M; j++) {
                if (!A[i][j]) {
                    cnt++;
                }
                if (!seen[cnc[i][j]]) {
                    seen[cnc[i][j]] = true;
                    cnt += sz[cnc[i][j]];
                }
                if (i > 1 && !seen[cnc[i-1][j]]) {
                    seen[cnc[i-1][j]] = true;
                    cnt += sz[cnc[i-1][j]];
                }
                if (i < N && !seen[cnc[i+1][j]]) {
                    seen[cnc[i+1][j]] = true;
                    cnt += sz[cnc[i+1][j]];
                }
            }
            ans = max(ans, cnt);
        }
        for (int j = 1; j <= M; j++) {
            int cnt = 0;
            vector<bool> seen(cur+1);
            for (int i = 1; i <= N; i++) {
                if (!A[i][j]) {
                    cnt++;
                }
                if (!seen[cnc[i][j]]) {
                    seen[cnc[i][j]] = true;
                    cnt += sz[cnc[i][j]];
                }
                if (j > 1 && !seen[cnc[i][j-1]]) {
                    seen[cnc[i][j-1]] = true;
                    cnt += sz[cnc[i][j-1]];
                }
                if (j < M && !seen[cnc[i][j+1]]) {
                    seen[cnc[i][j+1]] = true;
                    cnt += sz[cnc[i][j+1]];
                }
            }
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
}
