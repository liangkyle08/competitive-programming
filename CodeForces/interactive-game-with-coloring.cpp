#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
vector<int> adjList[101];
int color[101];
int K = 0;

void DFS(int node, int parent, int depth) {
    K = max(K, depth);
    color[node] = depth;
    for (auto child: adjList[node]) {
        if (parent == child) continue;
        DFS(child, node, depth+1);
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cin >> N;
    for (int u = 2; u <= N; u++) {
        int v;
        cin >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1, 0);
    cout << K << "\n" << flush;
    for (int i = 2; i <= N; i++) {
        cout << color[i] << " " << flush;
    } cout << "\n" << flush;
    while (true) {
        int t;
        cin >> t;
        if (t == -1 || t == 1) break;
        vector<int> cnt(K+1);
        for (int i = 1; i <= K; i++) {
            cin >> cnt[i];
        }
        for (int i = 1; i <= K; i++) {
            if (cnt[i] > 0) {
                cout << i << "\n" << flush;
                break;
            }
        }
    }
}
