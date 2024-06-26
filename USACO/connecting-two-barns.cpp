#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
vector<int> adjList[500001];
int comp[500001];
int cur = 1;
int compN = 0;

void DFS(int u) {
    if (comp[u]) return;
    if (u == N) compN = cur;
    comp[u] = cur;
    for (auto v: adjList[u]) {
        DFS(v);
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        if (comp[i]) continue;
        DFS(i);
        cur++;
    }
    vector<int> minDist1(cur, (1<<30));
    vector<int> minDistN(cur, (1<<30));
    int near1 = -1;
    int nearN = -1;
    for (int i = 1; i <= N; i++) {
        if (comp[i] == 1) near1 = i;
        if (comp[i] == compN ) nearN = i;
        if (near1 > -1) minDist1[comp[i]] = min(minDist1[comp[i]], i-near1);
        if (nearN > -1) minDistN[comp[i]] = min(minDistN[comp[i]], i-nearN);
    }
    near1 = -1;
    nearN = -1;
    for (int i = N; i >= 1; i--) {
        if (comp[i] == 1) near1 = i;
        if (comp[i] == compN ) nearN = i;
        if (near1 > -1) minDist1[comp[i]] = min(minDist1[comp[i]], near1-i);
        if (nearN > -1) minDistN[comp[i]] = min(minDistN[comp[i]], nearN-i);
    }
    long long ans = (1LL<<60);
    for (int i = 1; i < cur; i++) {
        ans = min(ans, (long long)minDist1[i]*(long long)minDist1[i]+(long long)minDistN[i]*(long long)minDistN[i]);
    }
    cout << ans << "\n";
    // Reset
    cur = 1;
    compN = 0;
    for (int i = 1; i <= N; i++) {
        adjList[i].clear();
        comp[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
