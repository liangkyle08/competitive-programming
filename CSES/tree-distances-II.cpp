#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
vector<int> adjList[200001];
vector<int> D[200001]; // Nodes at each depth
long long DP[200001]; // Sum of distances in subtree
int sz[200001]; // Size of subtree
int P[200001]; // Parent of each node

void DFS(int node, int parent, int depth) {
    sz[node] = 1;
    D[depth].push_back(node);
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node, depth+1);
        sz[node] += sz[child];
        DP[node] += DP[child]+sz[child];
        P[child] = node;
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1, 1);
    vector<long long> ans(N+1);
    for (int i = 1; i <= 200000; i++) {
        for (auto u: D[i]) {
            ans[u] = DP[u];
            if (P[u]) {
                ans[u] += ans[P[u]]-(ans[u]+sz[u])+(N-sz[u]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}
