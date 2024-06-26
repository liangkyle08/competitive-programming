#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[501][501];
int order[501][501];
bool adjMatrix[501][501];
vector<bool> seen;
int ans[501];

void DFS(int u, int node) {
    if (seen[u]) return;
    seen[u] = true;
    if (!ans[node] || order[node][u] < order[node][ans[node]]) {
        ans[node] = u;
    }
    for (int v = 1; v <= N; v++) {
        if (!adjMatrix[u][v]) continue;
        if (adjMatrix[v][u]) {
            DFS(v, node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        bool flag = false;
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            order[i][arr[i][j]] = j;
            if (flag) continue;
            adjMatrix[i][j] = true;
            if (arr[i][j] == i) flag = true;
        }
    }
    for (int i = 1; i <= N; i++) {
        seen.resize(N+1);
        DFS(i, i);
        seen.clear();
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}
