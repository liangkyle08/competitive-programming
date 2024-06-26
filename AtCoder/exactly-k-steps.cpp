#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
vector<int> adjList[200001];
int DP[20][200001];
int DP2[20][200001];
int oldDepth[200001];
int depth[200001];
int root = 1;
int maxDepth = 0;
bool onDiameter[200001];

void findRoot(int node, int parent) {
    if (oldDepth[node] > oldDepth[root]) {
        root = node;
    }
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        oldDepth[child] = oldDepth[node]+1;
        findRoot(child, node);
    }
}

void DFS(int node, int parent) {
    maxDepth = max(maxDepth, depth[node]);
    DP[0][node] = parent;
    for (int i = 1; i <= 18; i++) {
        DP[i][node] = DP[i-1][DP[i-1][node]];
    }
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        depth[child] = depth[node]+1;
        DFS(child, node);
    }
}

bool DFS2(int node, int parent) {
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        depth[child] = depth[node]+1;
        if (DFS2(child, node)) {
            onDiameter[node] = true;
            DP2[0][node] = child;
            for (int i = 1; i <= 18; i++) {
                DP2[i][node] = DP2[i-1][DP2[i-1][node]];
            }
            return true;
        }
    }
    if (depth[node] == maxDepth) {
        onDiameter[node] = true;
        return true;
    }
    return false;
}

int goingUp(int node, int k) {
    for (int i = 18; i >= 0; i--) {
        if ((1<<i) > k) continue;
        if (DP[i][node] == 0) continue;
        node = DP[i][node];
        k -= (1<<i);
    }
    if (k != 0) return -1;
    return node;
}

int goingDown(int node, int k) {
    for (int i = 18; i >= 0; i--) {
        if ((1<<i) > k) continue;
        if (DP2[i][node] == 0) continue;
        node = DP2[i][node];
        k -= (1<<i);
    }
    if (k != 0) return -1;
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    findRoot(1, 0);
    DFS(root, 0);
    DFS2(root, 0);
    cin >> Q;
    while (Q--) {
        int u, k;
        cin >> u >> k;
        for (int i = 18; i >= 0; i--) { // Get onto diameter
            if ((1<<i) > k) continue;
            if (DP[i][u] == 0) continue;
            if (!onDiameter[DP[i][u]]) {
                u = DP[i][u];
                k -= (1<<i);
            }
        }
        if (!onDiameter[u] && k > 1) {
            u = DP[0][u];
            k--;
        }
        cout << max(goingUp(u, k), goingDown(u, k)) << "\n";
    }
}
