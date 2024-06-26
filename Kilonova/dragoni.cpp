// OJI 2015 XI-XII: Problema 2
// Dragoni (Dragoons)
// https://kilonova.ro/problems/32

#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int arr[801];
vector<pair<int, int>> adjList[801];

void BFS() {
    int ans = 0;
    vector<bool> seen(N+1);
    queue<int> q;
    q.push(1);
    int farthest = arr[1];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!seen[u]) {
            seen[u] = true;
            ans = max(ans, arr[u]);
            for (auto [c, v]: adjList[u]) {
                if (c <= farthest) {
                    q.push(v);
                }
            }
        }
    }
    cout << ans << "\n";
}

void dijkstras() {
    vector<vector<int>> seen(N+1, vector<int>(N+1));
    vector<vector<int>> minCost(N+1, vector<int>(N+1, INT_MAX));
    minCost[1][1] = 0;
    priority_queue<array<int, 3>> pq; // min dist, node, fastest dragon
    pq.push({0, 1, 1});
    while (!pq.empty()) {
        int curCost = -pq.top()[0];
        int u = pq.top()[1];
        int w = pq.top()[2];
        pq.pop();
        if (arr[u] > arr[w]) {
            w = u;
        }
        if (!seen[u][w]) {
            seen[u][w] = true;
            for (auto [c, v]: adjList[u]) {
                if (arr[w] < c) continue;
                int newCost = curCost+c;
                if (newCost < minCost[v][w]) {
                    minCost[v][w] = newCost;
                    pq.push({-newCost, v, w});
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, minCost[N][i]);
    }
    cout << ans << "\n";
}

int main() {
    freopen("dragoni.in", "r", stdin);
    freopen("dragoni.out", "w", stdout);
    cin >> T >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adjList[u].emplace_back(c, v);
        adjList[v].emplace_back(c, u);
    }
    if (T == 1) BFS();
    else dijkstras();
}
