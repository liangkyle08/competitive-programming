#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int N, M;
vector<int> adjList[MAX_N + 5];
pair<long long, long long> comp[MAX_N + 5]; // # of nodes, # of edges
bool seen[MAX_N + 5];
int cur;

void DFS(int node) {
    if (seen[node]) return;
    seen[node] = true;
    comp[cur].fi++;
    for (auto &child: adjList[node]) {
        comp[cur].se++;
        DFS(child);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cur = 0;
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        cur++;
        DFS(i);
        comp[cur].se /= 2;
    }
    long long ans = 0;
    for (int i = 1; i <= cur; i++) {
        ans += (comp[i].fi) * (comp[i].fi - 1) / 2 - comp[i].se;
    }
    sort(comp + 1, comp + cur + 1);
    long long cnt = 0;
    for (int i = cur; i > 1; i--) {
        cnt += comp[i].fi;
        ans += (i == 2 ? 1 : cnt * comp[i - 1].fi);
    }
    cout << ans << "\n";
}
