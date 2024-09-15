#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int N, M;
vector<pair<int, long long>> adjList[100001];
bool seen[100001];
long long minCost[100001];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adjList[u].push_back({v, c}); // end and cost of the flight
    }
    for (int i = 2; i <= N; i++) {
        minCost[i] = LLONG_MAX;
    }
    priority_queue<pair<long long, int>> pq; // cost and node
    pq.push({0, 1});
    while (!pq.empty()) {
        pair<long long, int> node = pq.top();
        pq.pop();
        if (seen[node.se]) continue;
        seen[node.se] = true;
        for (auto child: adjList[node.se]) {
            long long cost = -node.fi + child.se;
            if (cost < minCost[child.fi]) {
                minCost[child.fi] = cost;
                pq.push({-cost, child.fi});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << minCost[i] << " ";
    } cout << "\n";
}