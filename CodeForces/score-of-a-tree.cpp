#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
vector<int> adjList[MAX_N+5];
int dist[MAX_N+5];

long long pow2(int X) {
    long long val = 1;
    long long Y = 2;
    while (X) {
        if (X & 1) {
            val *= Y;
            val %= MOD;
        }
        Y *= Y;
        Y %= MOD;
        X >>= 1;
    }
    return val;
}

void DFS(int node, int parent) {
    dist[node] = 1;
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        dist[node] = max(dist[node], dist[child]+1);
    }
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        adjList[i].clear();
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1);
    long long ans = 0;
    long long cur = pow2(N-1);
    for (int i = 1; i <= N; i++) {
        ans += cur * dist[i] % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
