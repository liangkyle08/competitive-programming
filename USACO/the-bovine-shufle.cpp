#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int adj[100001];
vector<int> state;
bool seen[100001];

bool DFS(int u, bool curState) {
    if (state[u]) return false;
    state[u] = 1;
    int v = adj[u];
    if (seen[v]) return false;
    if (state[v] == 1) {
        state[v] = 2;
        curState = true;
    }
    else {
        curState = DFS(v, curState);
    }
    if (!curState) return false;
    if (state[u] == 2) return false;
    state[u] = 2;
    return true;
}

void DFS2(int u) {
    if (seen[u] || !state[u]) return;
    seen[u] = true;
    DFS2(adj[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    cin >> N;
    for (int u = 1; u <= N; u++) {
        cin >> adj[u];
    }
    state.resize(N+1);
    for (int i = 1; i <= N; i++) {
        if (!state[i]) {
            DFS(i, false);
            DFS2(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (state[i] == 2) ans++;
    }
    cout << ans << "\n";
}
