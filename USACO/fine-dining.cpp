#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const long long LL_INF = (1LL << 60);

const int MAX_N = 5e4;

int N, M, K;
vector<pair<int, int>> adjList[MAX_N + 5];
long long dist[MAX_N + 5];
long long orig[MAX_N + 5];
bool seen[MAX_N + 5];

void Dijkstra(int src) {
    for (int i = 0; i <= N; i++) {
        seen[i] = false;
        dist[i] = (i == src ? 0 : LL_INF);
    }
    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        long long curDist = pq.top().fi;
        int node = pq.top().se;
        pq.pop();
        if (seen[node]) continue;
        seen[node] = true;
        for (auto [child, weight]: adjList[node]) {
            long long newDist = -curDist + weight;
            if (newDist < dist[child]) {
                dist[child] = newDist;
                pq.push({-dist[child], child});
            }
        }
    }
}

int main() {
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adjList[u].push_back({v, c});
        adjList[v].push_back({u, c});
    }
    Dijkstra(N);
    for (int i = 1; i <= N; i++) {
        orig[i] = dist[i];
    }
    for (int i = 1; i <= K; i++) {
        int ind, v;
        cin >> ind >> v;
        adjList[0].push_back({ind, orig[ind] - v});
    }
    Dijkstra(0);
    for (int i = 1; i < N; i++) {
        cout << (dist[i] <= orig[i]) << "\n";
    }
}
