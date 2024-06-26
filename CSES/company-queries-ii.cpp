// Binary Lifting and LCA
// https://cses.fi/problemset/task/1688/

#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> adjList[200001];
int DP[20][200001];
int depth[200001];

void DFS(int node, int parent) {
    DP[0][node] = parent; // One depth away is the parent
    for (int i = 1; i <= 18; i++) {
        DP[i][node] = DP[i-1][DP[i-1][node]]; // 4 = 2+2, 8 = 4+4, etc.
    }
    for (auto child: adjList[node]) {
        depth[child] = depth[node]+1; // Get depth of each node
        DFS(child, node);
    }
}

int solve(int a, int b) {
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
    for (int u = 2; u <= N; u++) {
        int v;
        cin >> v;
        adjList[v].push_back(u);
    }
    DFS(1, 0); // Parent != -1 or else undefined behavior
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
}
