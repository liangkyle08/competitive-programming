#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
vector<int> adjList[200001];
int upper[200001];
int lower[200001];
int ans = (1<<30);

void DFS(int node, int parent) {
    int total = 1;
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        total += upper[child]+lower[child];
    }
    upper[node] = total;
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        if (total-(upper[child]+lower[child]) < abs(upper[node]-lower[node])
            || (total-(upper[child]+lower[child]) == abs(upper[node]-lower[node])
                && total-(upper[child]+lower[child]) <= upper[child]+lower[child])) {
            upper[node] = total-(upper[child]+lower[child]);
            lower[node] = upper[child]+lower[child];
        }
        if (total-lower[child] < abs(upper[node]-lower[node])
            || (total-lower[child] == abs(upper[node]-lower[node])
                && total-lower[child] <= lower[child])) {
            upper[node] = total-lower[child];
            lower[node] = lower[child];
        }
    }
    cout << node << " " << upper[node] << " " << lower[node] << '\n';
    if (adjList[node].size() > 1) {
        int mx = max(N-total, max(upper[node], lower[node]));
        int mn = min(N-total, min(upper[node], lower[node]));
        ans = min(ans, mx-mn);
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
    for (int i = 1; i <= N; i++) {
        // Start from a leaf node
        if (adjList[i].size() == 1) {
            DFS(i, -1);
            break;
        }
    }
    cout << ans << "\n";
}
