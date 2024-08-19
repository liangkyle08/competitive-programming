#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N, M;
vector<int> adjList[MAX_N + 5];
vector<pair<int, int>> edges;
int in[MAX_N + 5];
int order[MAX_N + 5];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) adjList[i].clear();
    edges.clear();
    memset(in, 0, sizeof(in));
    memset(order, 0, sizeof(order));
    for (int i = 1; i <= M; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            edges.push_back({u, v});
        }
        if (t == 1) {
            adjList[u].push_back(v);
            in[v]++;
        }
    }
    queue<int> q;
    int cur = 1;
    for (int i = 1; i <= N; i++) {
        if (in[i]) continue;
        q.push(i);
        order[i] = cur;
        cur++;
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v: adjList[u]) {
            in[v]--;
            if (in[v]) continue;
            order[v] = cur;
            cur++;
            q.push(v);
        }
        cnt++;
    }
    if (cnt != N) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto &[u, v]: edges) {
        if (order[u] < order[v]) {
            cout << u << " " << v << "\n";
        }
        else {
            cout << v << " " << u << "\n";
        }
    }
    for (int u = 1; u <= N; u++) {
        for (auto &v: adjList[u]) {
            cout << u << " " << v << "\n";
        }
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
