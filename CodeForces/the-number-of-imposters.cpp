#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> adj2;
vector<int> A;
int total;
int ones;

void DFS(int node, int t) {
    if (A[node] && A[node] != t) total = -1;
    if (A[node] || total == -1) return;
    A[node] = t;
    total++;
    ones += (A[node] == 1);
    for (auto [child, t2]: adj[node]) {
        if (A[node] == 1) {
            DFS(child, t2);
        }
        else {
            DFS(child, ((t2 == 1) ? 2 : 1));
        }
    }
    for (auto [child, t2]: adj2[node]) {
        if (A[node] == t2) {
            DFS(child, 1);
        }
        else {
            DFS(child, 2);
        }
    }
}


void solve() {
    cin >> N >> M;
    adj.clear();
    adj.resize(N+1);
    adj2.clear();
    adj2.resize(N+1);
    for (int i = 1; i <= M; i++) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        adj[u].push_back({v, (s == "crewmate" ? 1 : 2)});
        adj2[v].push_back({u, (s == "crewmate" ? 1 : 2)});
    }
    A.clear();
    A.resize(N+1);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i]) continue;
        total = 0;
        ones = 0;
        DFS(i, 1);
        if (total == -1) {
            cout << -1 << "\n";
            return;
        }
        ans += max(ones, total-ones);
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
