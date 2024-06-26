#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, D;
vector<int> adjList[101];
long long numLeaves[101]; // # of leaves at each depth
long long numNodes[101];
long long DP[10001][2]; // Number of nodes, number of leaves at each depth

void DFS(int node, int parent, int depth) {
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node, depth+1);
    }
    if ((int)adjList[node].size() == 1 && node != 1) { // One edge = is a leaf
        numLeaves[depth]++;
    }
    numNodes[depth]++;
}

int main() {
    freopen("tairos.in", "r", stdin);
    freopen("tairos.out", "w", stdout);
    cin >> N >> D;
    for (int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1, 0);
    for (int i = 0; i <= 100; i++) {
        DP[i][0] = numNodes[i];
        DP[i][1] = numLeaves[i];
    }
    for (int i = 0; i <= D; i++) {
        for (int j = 100; j >= 1; j--) {
            if (i+j > D) continue;
            DP[i+j][0] = (DP[i+j][0]+(DP[i][1]*numNodes[j]) % MOD) % MOD;
            DP[i+j][1] = (DP[i+j][1]+(DP[i][1]*numLeaves[j]) % MOD) % MOD;
        }
    }
    cout << DP[D][0] << "\n";
}
