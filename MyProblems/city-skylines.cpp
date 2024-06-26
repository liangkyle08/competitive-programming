#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int MAX_N = 3e5;

int N, M;
int val[3*MAX_N+1];
vector<int> adjList[MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int cur = N+1;
    vector<pair<int, int>> newEdges;
    for (int u = 1; u <= N; u++) {
        int sum = 0;
        for (auto v: adjList[u]) {
            sum += val[v];
        }
        if (val[u] == sum) continue;
        int cnt = 0;
        int newVal = 0;
        if (sum < val[u]) {
            newVal = 1;
            if (val[u] == -1) cnt = 3;
            if (val[u] == 0) cnt = 2;
            if (val[u] == 1) cnt = 1;
        }
        if (sum > val[u]) {
            newVal = -1;
            if (val[u] == -1) cnt = 1;
            if (val[u] == 0) cnt = 2;
            if (val[u] == 1) cnt = 3;
        }
        for (int i = 1; i <= abs(sum-val[u]); i++) {
            for (int j = 0; j < cnt; j++) {
                val[cur+j] = newVal;
            }
            cur += cnt;
        }
    }
    cout << cur-N-1 << "\n";
}
