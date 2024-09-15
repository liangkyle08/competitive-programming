#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 5e4;

int N, M, P;
long long T;
vector<pair<int, array<long long, 4>>> adjList[MAX_N + 5];
bool seen[MAX_N + 5];
long long minCost[MAX_N + 5];

int main() {
    cin >> N >> M >> P >> T;
    for (int i = 1; i <= M; i++) {
        int u, v;
        long long a, b, c, d;
        cin >> u >> v >> a >> b >> c >> d;
        adjList[u].push_back({v, {a, b, c, d}});
    }
    for (int i = 2; i <= N; i++) {
        minCost[i] = LL_INF;
    }
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        long long curCost = pq.top().fi;
        int node = pq.top().se;
        pq.pop();
        if (seen[node]) continue;
        seen[node] = true;
        for (auto [child, t]: adjList[node]) {
            long long a = t[0];
            long long b = t[1];
            long long c = t[2];
            if (curCost > b) continue; // Missed the bus
            long long newCost = curCost;
            if (curCost < a) {
                newCost += (a - curCost) + (c - a); // Wait time;
            }
            else {
                newCost += (c - curCost);
            }
            if (node == P && newCost < T) {
                newCost += T - c;
            }
            if (newCost >= minCost[child]) continue;
            minCost[child] = newCost;
            pq.push({-newCost, child});
        }
    }
    if (minCost[P] != LL_INF) {
        cout << -1 << "\n";
        return 0;
    }
    cout << minCost[P] << "\n";
}
