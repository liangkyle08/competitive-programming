#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 3e5;

int T, N;
long long A[MAX_N+5];
vector<int> adjList[MAX_N+5];
long long DP[20][MAX_N+5];

void DFS(int node, int parent) {
    for (auto &child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        for (int i = 1; i <= 19; i++) {
            long long val = LL_INF;
            for (int j = 1; j <= 19; j++) {
                if (i == j) continue;
                val = min(val, DP[j][child]);
            }
            DP[i][node] += val;
        }
    }
    for (int i = 1; i <= 19; i++) {
        DP[i][node] += i * A[node];
    }
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        adjList[i].clear();
        for (int j = 1; j <= 19; j++) {
            DP[j][i] = 0;
        }
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1);
    long long ans = LL_INF;
    for (int i = 1; i <= 19; i++) {
        ans = min(ans, DP[i][1]);
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
