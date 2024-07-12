#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = 1e9;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;
const int MAX_M = 1e5;

int N, M;
int pos[MAX_N+5];
int weights[MAX_M+5];
vector<pair<int, int>> adjList[MAX_N+5];
int cnc[MAX_N+5];
int cnt;

void DFS(int u, int X) {
    if (cnc[u]) return;
    cnc[u] = cnt;
    for (auto [v, w]: adjList[u]) {
        if (w < X) continue;
        DFS(v, X);
    }
}

bool check(int X) {
    memset(cnc, 0, sizeof(cnc));
    cnt = 1;
    for (int i = 1; i <= N; i++) {
        if (cnc[i]) continue;
        DFS(i, X);
        cnt++;
    }
    for (int i = 1; i <= N; i++) {
    }
    for (int i = 1; i <= N; i++) {
        if (cnc[i] == cnc[pos[i]]) continue;
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> pos[i];
    }
    int j = 1;
    weights[0] = -1;
    for (int i = 1; i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
        weights[j] = w;
        j++;
    }
    sort(weights+1, weights+M+1);
    int high = INF;
    int low = 0;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid-1;
        }
    }
    cout << (low == INF ? -1 : low) << "\n";
}
