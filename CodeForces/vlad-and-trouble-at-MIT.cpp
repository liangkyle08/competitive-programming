#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
string s;
vector<vector<int>> adjList;
int type[100001]; // P = 1, S = 2
int DP[3][100001];

void DFS(int node, int parent) {
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        if (type[node] == 1) {
            if (type[child] == 1) {
                DP[1][node] += DP[1][child];
            }
            if (type[child] == 2) {
                DP[1][node] += DP[2][child]+1;
            }
            if (type[child] == 3) {
                DP[1][node] += min(DP[1][child], DP[2][child]+1);
            }
        }
        if (type[node] == 2) {
            if (type[child] == 1) {
                DP[2][node] += DP[1][child]+1;
            }
            if (type[child] == 2) {
                DP[2][node] += DP[2][child];
            }
            if (type[child] == 3) {
                DP[2][node] += min(DP[1][child]+1, DP[2][child]);
            }
        }
        if (type[node] == 3) {
            if (type[child] == 1) {
                DP[1][node] += DP[1][child];
                DP[2][node] += DP[1][child]+1;
            }
            if (type[child] == 2) {
                DP[1][node] += DP[2][child]+1;
                DP[2][node] += DP[2][child];
            }
            if (type[child] == 3) {
                DP[1][node] += min(DP[1][child], DP[2][child]+1);
                DP[2][node] += min(DP[1][child]+1, DP[2][child]);
            }
        }
    }
}

void solve() {
    cin >> N;
    adjList.clear();
    adjList.resize(N+1);
    for (int u = 1; u <= N; u++) {
        DP[1][u] = 0;
        DP[2][u] = 0;
        if (u > 1) {
            int v;
            cin >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    cin >> s;
    for (int i = 1; i <= N; i++) {
        if (s[i-1] == 'P') type[i] = 1;
        if (s[i-1] == 'S') type[i] = 2;
        if (s[i-1] == 'C') type[i] = 3;
    }
    DFS(1, 0);
    if (type[1] == 1) {
        cout << DP[1][1] << "\n";
    }
    if (type[1] == 2) {
        cout << DP[2][1] << "\n";
    }
    if (type[1] == 3) {
        cout << min(DP[1][1], DP[2][1]) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> T;
    while (T--) {
        solve();
    }
}
