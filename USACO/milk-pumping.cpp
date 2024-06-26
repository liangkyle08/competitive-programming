#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

struct Edge {
    int child, cost, rate, ind;
};

int N, M;
vector<Edge> adjList[1001];
int skip[1001];
vector<bool> seen;
vector<int> maxCost;

void DFS(int u, int curSkip) {
    if (seen[u]) return;
    seen[u] = true;
    for (auto [v, c, f, i]: adjList[u]) {
        if (skip[i] < curSkip) continue;
        maxCost[v] = max(maxCost[v], maxCost[u]+c);
        DFS(v, curSkip);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> M;
    vector<pair<int, int>> arr;
    for (int i = 1; i <= M; i++) {
        int u, v, c, f;
        cin >> u >> v >> c >> f;
        adjList[u].push_back({v, c, f, i});
        adjList[v].push_back({u, c, f, i});
        arr.push_back({f, i});
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= M; i++) {
        skip[arr[i-1].se] = i;
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        seen.clear();
        seen.resize(N+1);
        maxCost.clear();
        maxCost.resize(N+1);
        DFS(1, i);
        for (int j = 1; j <= N; j++) {
            cout << j << " " << maxCost[j] << "\n";
        }
        cout << maxCost[N] << " " << arr[i-1].fi << "\n";
        ans = max(ans, (maxCost[N]*1000000)/(arr[i-1].fi));
    }
    cout << ans << "\n";
}
