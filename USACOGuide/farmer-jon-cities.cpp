#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

struct Edge {
    int child;
    long long length;
    bool newRoad;
};

int N, M, K, s, t;
vector<Edge> adjList[100001];
long long minOldDist[100001];
long long minNewDist[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> M >> K >> s >> t;
    for (int i = 1; i <= M; i++) {
        int u, v;
        long long L;
        cin >> u >> v >> L;
        adjList[u].push_back({v, L, false});
    }
    for (int i = 1; i <= K; i++) {
        int u, v;
        long long L;
        cin >> u >> v >> L;
        adjList[u].push_back({v, L, true});
    }
    for (int i = 1; i <= N; i++) {
        minOldDist[i] = (1LL<<60);
        minNewDist[i] = (1LL<<60);
    }
    minOldDist[s] = 0;
    minNewDist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, L, newRoad]: adjList[u]) {
            if (newRoad) {
                if (minOldDist[u]+L < minNewDist[v]) {
                    minNewDist[v] = minOldDist[u]+L;
                    q.push(v);
                }
            }
            else {
                bool flag = false;
                if (minOldDist[u]+L < minOldDist[v]) {
                    minOldDist[v] = minOldDist[u]+L;
                    flag = true;
                }
                if (minNewDist[u]+L < minNewDist[v]) {
                    minNewDist[v] = minNewDist[u]+L;
                    flag = true;
                }
                if (flag) q.push(v);
            }
        }
    }
    cout << min(minNewDist[t], minOldDist[t]) << "\n";
}
