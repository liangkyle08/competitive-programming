#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int N, K;
vector<int> adjList[MAX_N + 5];
bool val[MAX_N + 5];
int sub[MAX_N + 5];
long long cnt[MAX_N + 5];

void DFS(int node, int parent) {
    sub[node] = val[node];
    for (auto &child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        sub[node] += sub[child];
    }
    cnt[node] = min(sub[node], 2 * K - sub[node]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i <= 2 * K; i++) {
        int v;
        cin >> v;
        val[v] = true;
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1);
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += cnt[i];
    }
    cout << ans << "\n";
}
