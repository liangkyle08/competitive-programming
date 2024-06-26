#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
vector<int> adjList[200001];
int DP[20][200001];
int depth[200001];

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, 0);
    while (Q--) {
        int a, b;
        cin >> a >> b;
        int aDepth = depth[a];
        int bDepth = depth[b];
        int lcaDepth = depth[LCA(a, b)];
        cout << (aDepth-lcaDepth)+(bDepth-lcaDepth) << "\n";
    }
}