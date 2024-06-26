#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

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
        if (seen[node.s]) continue;
        seen[node.s] = true;
        for (auto child: adjList[node.s]) {
            long long cost = -node.f + child.s;
            if (cost < minCost[child.f]) {
                minCost[child.f] = cost;
                pq.push({-cost, child.f});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << minCost[i] << " ";
    } cout << "\n";
}