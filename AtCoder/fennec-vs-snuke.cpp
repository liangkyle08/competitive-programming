#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
vector<int> adjList[100001];
vector<int> path;
int cnt = 0;

bool DFS1(int node, int parent) {
    if (node == N) {
        path.push_back(N);
        return true;
    }
    bool flag = false;
    for (auto child: adjList[node]) {
        if (parent == child) continue;
        if (DFS1(child, node)) flag = true;
    }
    if (flag) {
        path.push_back(node);
    }
    return flag;
}

void DFS2(int node, int parent, int skip) {
    cnt++;
    for (auto child: adjList[node]) {
        if (child == parent || child == skip) continue;
        DFS2(child, node, skip);
    }
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
    DFS1(1, -1);
    reverse(path.begin(), path.end());
    DFS2(1, -1, path[(((int)path.size()+1)/2)]);
    if (cnt > N-cnt) {
        cout << "Fennec\n";
    }
    else {
        cout << "Snuke\n";
    }
}
