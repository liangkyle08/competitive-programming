#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
vector<int> adjList[100001];
long long DP[2][1000001]; // Black = 1, White = 0

void DFS(int node, int parent) {
    DP[1][node] = 1LL;
    DP[0][node] = 1LL;
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        DP[1][node] = (DP[1][node]*DP[0][child]) % MOD;
        DP[0][node] = (DP[0][node]*(DP[1][child]+DP[0][child]) % MOD) % MOD;
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
    if (N == 1) {
        cout << 2 << "\n";
    }
    else {
        cout << (DP[1][1]+DP[0][1]) % MOD << "\n";
    }
}
