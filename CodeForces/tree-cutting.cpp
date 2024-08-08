#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int T, N, K;
vector<int> adjList[MAX_N+5];
int subTree[MAX_N+5];
int brokenEdges;

void DFS(int node, int parent, int X) {
    subTree[node] = 1;
    for (auto &child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node, X);
        subTree[node] += subTree[child];
    }
    if (subTree[node] >= X && node != 1) {
        subTree[node] = 0;
        brokenEdges++;
    }
    if (subTree[node] < X && node == 1) {
        brokenEdges--;
    }
}

void solve() {
    cin >> N >> K;
    memset(adjList, {}, sizeof(adjList));
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int low = 1;
    int high = N;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        brokenEdges = 0;
        memset(subTree, 0, sizeof(subTree));
        DFS(1, -1, mid);
        if (brokenEdges >= K) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
