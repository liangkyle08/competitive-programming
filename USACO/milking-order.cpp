#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int MAX_N = 1e5;
const int MAX_M = 5e4;

int N, M;
vector<pair<int, int>> edges[MAX_M + 5];
vector<int> adjList[MAX_N + 5];
int in[MAX_N + 5];
int ans[MAX_N + 5];

bool check(int K) {
    for (int i = 1; i <= N; i++) {
        adjList[i].clear();
        in[i] = 0;
    }
    for (int i = 1; i <= K; i++) {
        for (auto &[u, v]: edges[i]) {
            adjList[u].push_back(v);
            in[v]++;
        }
    }
    priority_queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in[i] != 0) continue;
        q.push(-i);
    }
    for (int i = 1; i <= N; i++) {
        if (q.empty()) return false;
        int u = -q.top();
        q.pop();
        ans[i] = u;
        for (auto &v: adjList[u]) {
            in[v]--;
            if (in[v] == 0) q.push(-v);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int m;
        cin >> m;
        int u = -1;
        for (int j = 1; j <= m; j++) {
            int v;
            cin >> v;
            if (u != -1) edges[i].push_back({u, v});
            u = v;
        }
    }
    int low = 0;
    int high = M;
    while (low < high) {
        int mid = (low + high + 1)/2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    check(low);
    for (int i = 1; i <= N; i++) {
        cout << ans[i];
        cout << (i < N ? " " : "\n");
    }
}
