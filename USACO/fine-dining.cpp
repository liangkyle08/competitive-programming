#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M, K;
vector<pair<long long, int>> adjList[50001];
long long val[500001]; // Value of the K nodes
long long A[50001]; // Min cost to node N
long long B[50001]; // Min cost to one of the K nodes

void Dijkstra(bool flag) {
    priority_queue<pair<long long, int>> pq;
    vector<bool> seen(N+1);
    if (flag) {
        for (int i = 1; i <= N; i++) {
            A[i] = (1LL<<60);
        }
        A[N] = 0LL;
        pq.push({0LL, N});
    }
    else {
        for (int i = 1; i <= N; i++) {
            B[i] = (1LL<<60);
            if (val[i]) {
                B[i] = A[i]-val[i];
                pq.push({val[i], i});
            }
        }
    }
    while (!pq.empty()) {
        int u = pq.top().se;
        long long curCost = -pq.top().fi;
        pq.pop();
        if (seen[u]) continue;
        seen[u] = true;
        for (auto [c, v]: adjList[u]) {
            long long newCost = curCost+c;
            if (flag) {
                if (newCost < A[v]) {
                    A[v] = newCost;
                    pq.push({-newCost, v});
                }
            }
            else {
                if (newCost < B[v]) {
                    B[v] = newCost;
                    pq.push({-newCost, v});
                }
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
        adjList[u].push_back({c, v});
        adjList[v].push_back({c, u});
    }
    for (int i = 1; i <= K; i++) {
        int ind;
        long long c;
        cin >> ind >> c;
        val[ind] = c;
    }
    Dijkstra(true);
    Dijkstra(false);
    for (int i = 1; i < N; i++) {
        if (B[i] <= A[i]) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
}
