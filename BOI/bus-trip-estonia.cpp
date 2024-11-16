#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 5e4;

struct Edge {
    int u, v;
    long long a, b, c, d;
    long long cur = 0;
};

int N, M, P;
long long T;
Edge edges[MAX_N + 5];
set<int> times;
unordered_map<int, vector<int>> depart;
unordered_map<int, vector<int>> arrive;
long long dist[MAX_N + 5];

int main() {
    cin >> N >> M >> P >> T;
    times.insert(0);
    times.insert(T);
    for (int i = 1; i <= M; i++) {
        int u, v;
        long long a, b, c, d;
        cin >> u >> v >> a >> b >> c >> d;
        times.insert(a);
        times.insert(b);
        times.insert(c);
        times.insert(d);
        edges[i] = {u, v, a, b, c, d, a};
        depart[a].push_back(i);
        arrive[d].push_back(i);
    }
    for (int i = 1; i <= N; i++) dist[i] = -LL_INF;
    dist[1] = 0;
    for (auto &time: times) {
        if (time > T) break;
        for (auto i: arrive[time]) {
            auto &[u, v, a, b, c, d, cur] = edges[i];
            dist[v] = max(dist[v], cur);
        }
        for (auto i: depart[time]) {
            auto &[u, v, a, b, c, d, cur] = edges[i];
            cur = dist[u] + (c - b);
        }
    }
    long long ans = T - dist[P];
    cout << (ans >= INF ? -1 : ans) << "\n";
}
