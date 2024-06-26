#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M, K;
int adjList[100001];
bool seen[100001];
int ans[100001];
vector<int> cycle;

void DFS(int node) {
    if (seen[node]) return;
    seen[node] = true;
    cycle.push_back(node);
    DFS(adjList[node]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        adjList[i] = i;
    }
    for (int i = 1; i <= M; i++) {
        int L, R;
        cin >> L >> R;
        reverse(adjList+L, adjList+R+1);
    }
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        cycle.clear();
        DFS(i);
        int len = (int)cycle.size();
        int shift = K % (len);
        for (int j = 0; j < len; j++) {
            ans[cycle[j]] = cycle[(j+shift) % len];
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}
