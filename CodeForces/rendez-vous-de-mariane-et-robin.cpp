#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N, M, H;

void solve() {
    cin >> N >> M >> H;
    vector<bool> A(N + 5);
    for (int i = 1; i <= H; i++) {
        int v;
        cin >> v;
        A[v] = true;
    }
    vector<vector<pair<int, long long>>> adjList(N + 5);
    for (int i = 1; i <= M; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adjList[u].push_back({v, c});
        adjList[v].push_back({u, c});
    }
    auto dijkstra = [&](int root) {
        vector<vector<long long>> minCost(2, vector<long long>(N + 5, LL_INF));
        priority_queue<pair<long long, pair<int, bool>>> pq;
        minCost[0][root] = 0;
        if (A[root]) minCost[1][root] = 0;
        pq.push({0, {root, A[root]}});
        while (!pq.empty()) {
            long long curCost = -pq.top().fi;
            int node = pq.top().se.fi;
            bool flag = pq.top().se.se;
            pq.pop();
            if (minCost[flag][node] != curCost) continue;
            if (A[node]) flag = true;
            for (auto [child, c]: adjList[node]) {
                long long newCost = curCost + (flag ? c / 2 : c);
                if (newCost < minCost[flag][child]) {
                    minCost[flag][child] = newCost;
                    pq.push({-newCost, {child, flag}});
                }
            }
        }
        vector<long long> ans(N + 5);
        for (int i = 1; i <= N; i++) {
            ans[i] = min(minCost[0][i], minCost[1][i]);
        }
        return ans;
    };
    auto minCost1 = dijkstra(1);
    auto minCostN = dijkstra(N);
    long long ans = LL_INF;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, max(minCost1[i], minCostN[i]));
    }
    cout << (ans == LL_INF ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}