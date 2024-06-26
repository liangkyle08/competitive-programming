#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int val[16001];
int DP[16001];
vector<int> adjList[16001];

void DFS(int node, int parent) {
    DP[node] = val[node];
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        if (DP[child] > 0) {
            DP[node] += DP[child];
        }
    }
}

int main() {
    freopen("asmax.in", "r", stdin);
    freopen("asmax.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> val[i];
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1);
    int ans = -1000;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, DP[i]);
    }
    cout << ans << "\n";
}
