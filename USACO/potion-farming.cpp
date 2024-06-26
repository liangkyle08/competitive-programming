#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int room[100001];
vector<int> spawn[100001];
vector<int> adjList[100001];
int leafCnt;
int ans;

int DFS(int node, int parent) {
    int openPaths = 0;
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        int childOpenPaths = DFS(child, node);
        openPaths += childOpenPaths;
    }
    if ((int)adjList[node].size() == 1 && node != 1) openPaths = 1;
    int numPotions = 0;
    for (auto v: spawn[node]) {
        if (v <= leafCnt) {
            numPotions++;
        }
    }
    ans += min(numPotions, openPaths);
    return max(0, openPaths-numPotions);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> room[i];
        spawn[room[i]].push_back(i);
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    leafCnt = 0;
    for (int i = 2; i <= N; i++) { // Node 1 doesn't count as leaf
        if ((int)adjList[i].size() == 1) {
            leafCnt++;
        }
    }
    ans = 0;
    DFS(1, -1);
    cout << ans << "\n";
}
