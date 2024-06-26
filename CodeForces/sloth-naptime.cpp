#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
vector<int> adjList[300001];
int DP[20][300001];
int depth[300001];

void DFS(int node, int parent) {
    DP[0][node] = parent; // One depth away is the parent
    for (int i = 1; i <= 18; i++) {
        DP[i][node] = DP[i-1][DP[i-1][node]]; // 4 = 2+2, 8 = 4+4, etc.
    }
    for (auto child: adjList[node]) {
        if (parent == child) continue;
        depth[child] = depth[node]+1; // Get depth of each node
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
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, 0); // Parent != -1 or else undefined behavior
    cin >> Q;
    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int lca = LCA(a, b);
        if (c >= depth[a]+depth[b]-2*depth[lca]) { // Sloth can traverse completely
            cout << b << "\n";
            continue;
        }
        if (c <= depth[a]-depth[lca]) { // Sloth stops before (or at) LCA
            for (int i = 18; i >= 0; i--) {
                if ((1<<i) <= c) {
                    a = DP[i][a];
                    c -= (1<<i);
                }
            }
            cout << a << "\n";
        }
        else { // Sloth stops after LCA
            c = depth[a]+depth[b]-2*depth[lca]-c;
            for (int i = 18; i >= 0; i--) {
                if ((1<<i) <= c) {
                    b = DP[i][b];
                    c -= (1<<i);
                }
            }
            cout << b << "\n";
        }
    }
}
