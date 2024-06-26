// Codeforces Round 881 (Div. 3)
// D. Apple Tree
// https://codeforces.com/contest/1843/problem/D

#include <bits/stdc++.h>
using namespace std;

int T, N, Q;
vector<int> adjList[200001];
long long leaves[200001];

void DFS(int node = 1, int parent = -1) {
    int cnt = 0;
    for (auto child: adjList[node]) {
        if (child != parent) {
            cnt++;
            DFS(child, node);
            leaves[node] += leaves[child];
        }
    }
    if (cnt == 0) {
        leaves[node] = 1;
    }
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        adjList[i].clear();
        leaves[i] = 0;
    }
    for(int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS();
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        cout << (leaves[x])*(leaves[y]) << "\n";
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
