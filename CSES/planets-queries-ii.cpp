#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int MAX_N = 2e5;

int N, Q;
int adj[MAX_N + 5];
vector<int> rev[MAX_N + 5];
int cycleID[MAX_N + 5];
int DP[20][MAX_N + 5];
int depth[MAX_N + 5];

void DFS(int node, int parent) {
    DP[0][node] = parent;
    for (int i = 1; i <= 18; i++) {
        DP[i][node] = DP[i-1][DP[i-1][node]];
    }
    for (auto child: adjList[node]) {
        depth[child] = depth[node]+1;
        DFS(child, node);
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = 18; i >= 0; i--) { // Get a and b to the same level
        if (depth[a]-(1<<i) >= depth[b]) {
            a = DP[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 18; i >= 0; i--) { // Get as close as possible to the same node
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
    for (int u = 1; u <= N; u++) {
        int v;
        cin >> v;
        adj[u] = v;
        rev[v].push_back(u);
        cycleID[u] = -2;
    }
    vector<map<int, int>> cycles;
    for (int u = 1; u <= N; u++) {
        if (cycleID[u] != -2) continue;
        vector<int> path = {u};
        int cur = u;
        while (cycleID[adj[cur]] == -2) {
            cur = adj[cur];
            cycleID[cur] = -3;
            path.push_back(cur);
        }
        map<int, int> cycle;
        bool inCycle = false;
        for (auto v: path) {
            if (v == adj[cur]) inCycle = true;
            if (inCycle) cycle[v] = (int)cycle.size();
            cycleID[v] = (inCycle ? (int)cycle.size() : -1);
        }
        cycles.push_back(cycle);
    }
}
