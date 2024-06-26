#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
vector<int> adjList[200001];
set<pair<int, int>> depth[200001]; // Nodes at each depth (sorted by DP val)
int DP[200001]; // Max distance in the subtree
int DP2[200001]; // Max distance outside the subtree;
pair<bool, int> parent[200001]; // Parent of each node + if child contributes

void DFS(int node, int curParent, int curDepth) {
    int finalChild = 0;
    parent[node] = {false, 0};
    for (auto child: adjList[node]) {
        if (child == curParent) continue;
        DFS(child, node, curDepth+1);
        if (DP[child]+1 > DP[node]) {
            DP[node] = DP[child]+1;
            finalChild = child;
        }
        parent[child] = {false, node};
    }
    depth[curDepth].insert({-DP[node], node});
    parent[finalChild] = {true, node};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1, 1);
    for (int i = 1; i <= 200000; i++) {
        if (depth[i].empty()) continue;
        for (auto [t1, u]: depth[i]) {
            if (!parent[u].fi and parent[u].se) { // Can compare with parent
                DP2[u] = max(DP[parent[u].se]+1, DP2[parent[u].se]+1);
            }
            else { // Must compare with siblings
                for (auto [t2, v]: depth[i]) {
                    if (u == v) continue;
                    DP2[u] = max(DP2[u], DP[v]+2);
                    break;
                }
                if (!parent[u].se) continue;
                DP2[u] = max(DP2[u], DP2[parent[u].se]+1); // Not using the subtree distance
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << max(DP[i], DP2[i]) << " ";
    } cout << "\n";
}
