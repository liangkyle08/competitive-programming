#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
vector<int> adjList[200001];
int DP[2][2000001]; // Max number of pairs in the each subtree (1 = with or 0 = without the current node)

void DFS(int node, int parent) {
    vector<pair<int, int>> maxPairs;
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        DP[0][node] += max(DP[0][child], DP[1][child]);
    }
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DP[1][node] = max(DP[1][node], (DP[0][node]-max(DP[0][child], DP[1][child]))+DP[0][child]+1);
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
    DFS(1, -1);
    cout << max(DP[1][1], DP[0][1]) << "\n";
}
