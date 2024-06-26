// Hints: https://gist.github.com/Juanito98/bc3e355d2e0fabdffe3d89474c6d1238

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
vector<int> adjList[50001];
int DP[20][50001];
int depth[50001];
int sol[50001];

void DFS(int node, int parent) {
    DP[0][node] = parent;
    for (int i = 1; i <= 18; i++) {
        DP[i][node] = DP[i-1][DP[i-1][node]];
    }
    for (auto child: adjList[node]) {
        if (parent == child) continue;
        depth[child] = depth[node]+1;
        DFS(child, node);
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = 18; i >= 0; i--) {
        if (depth[a]-(1<<i) >= depth[b]) {
            a = DP[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 18; i >= 0; i--) {
        if (DP[i][a] != DP[i][b]) {
            a = DP[i][a];
            b = DP[i][b];
        }
    }
    return DP[0][a];
}

void DFS2(int node, int parent) {
    for (auto child: adjList[node]) {
        if (parent == child) continue;
        DFS2(child, node);
        sol[node] += sol[child];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, 0);
    while (K--) {
        int u, v;
        cin >> u >> v;
        int lca = LCA(u, v);
        sol[u]++;
        sol[v]++;
        sol[lca]--;
        sol[DP[0][lca]]--;
    }
    DFS2(1, 0);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, sol[i]);
    }
    cout << ans << '\n';
}
