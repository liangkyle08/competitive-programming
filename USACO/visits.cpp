#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
pair<int, long long> adj[100001];
int seen[100001];
bool flag;
int cycleEnd;

long long DFS(int u, long long minEdge) {
    if (seen[u] == 2) return minEdge;
    if (seen[u] == 1) {
        flag = true;
        cycleEnd = u;
        return minEdge;
    }
    seen[u] = 1;
    minEdge = DFS(adj[u].fi, minEdge);
    if (flag && seen[u] == 1) {
        minEdge = min(minEdge, adj[u].se);
    }
    seen[u] = 2;
    if (u == cycleEnd) {
        flag = false;
    }
    return minEdge;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    long long ans = 0LL;
    for (int i = 1; i <= N; i++) {
        int a;
        long long v;
        cin >> a >> v;
        adj[i] = {a, v};
        ans += v;
    }
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        flag = false;
        cycleEnd = 0;
        long long v;
        v = DFS(i, (1LL<<60));
        if (v != (1LL<<60)) {
            ans -= v;
        }
    }
    cout << ans << "\n";
}
