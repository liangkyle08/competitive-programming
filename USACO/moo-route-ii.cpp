#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

struct Edge {
    int depart, v, arrive;
};

int N, M;
int A[MAX_N + 5];
int dist[MAX_N + 5];
vector<Edge> adjList[MAX_N + 5];

bool cmp(Edge X, Edge Y) {
    return X.depart < Y.depart;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, depart, v, arrive;
        cin >> u >> depart >> v >> arrive;
        adjList[u].push_back({depart, v, arrive});
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        cin >> A[i];
    }
    dist[1] = 0;
    for (int u = 1; u <= N; u++) {
        for (auto &[depart, v, arrive]: adjList[u]) {
            depart -= A[u];
        }
        sort(adjList[u].begin(), adjList[u].end(), cmp);
    }
    queue<Edge> q;
    for (auto &t: adjList[1]) {
        q.push(t);
    }
    while (!q.empty()) {
        int v = q.front().v;
        int arrive = q.front().arrive;
        q.pop();
        dist[v] = min(dist[v], arrive);
        while (!adjList[v].empty() && adjList[v].back().depart >= arrive) {
            q.push(adjList[v].back());
            adjList[v].pop_back();
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
}
