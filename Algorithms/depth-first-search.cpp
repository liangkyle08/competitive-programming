#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 5e5;

int N, M;
vector<int> adjList[MAX_N + 5];
bool seen[MAX_N + 5];
int comp[MAX_N + 5];
int cnc;

void DFS(int u) {
    if (seen[u]) return;
    seen[u] = true;
    for (auto &v: adjList[u]) {
        DFS(v);
    }
}

void findComp(int u) {
    if (comp[u]) return;
    comp[u] = cnc;
    for (auto &v: adjList[u]) {
        DFS(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    // memset(seen, false, sizeof(seen));
    // memset(comp, false, sizeof(comp));
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // adjList[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        DFS(i);
    }
    /* Connected Components
    cnt = 1;
    for (int i = 1; i <= N; i++) {
        if (comp[i]) continue;
        findComp(i);
        cnc++;
    }
    */
}
