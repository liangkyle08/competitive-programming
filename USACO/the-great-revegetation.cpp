#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
vector<pair<int, bool>> adjList[100001];
int color[100001];
bool pos = true;

void DFS(int node, int curColor) {
    if (color[node]) {
        if (color[node] != curColor) pos = false;
        return;
    }
    color[node] = curColor;
    for (auto [child, t]: adjList[node]) {
        if (t) {
            DFS(child, curColor);
            continue;
        }
        if (curColor == 1) DFS(child, 2);
        else DFS(child, 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        char t;
        int u, v;
        cin >> t >> u >> v;
        adjList[u].push_back({v, t == 'S'});
        adjList[v].push_back({u, t == 'S'});
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!color[i]) {
            DFS(i, 1);
            cnt++;
        }
    }
    if (pos) {
        cout << 1;
        for (int i = 1; i <= cnt; i++) {
            cout << 0;
        } cout << "\n";
    }
    else {
        cout << 0 << "\n";
    }

}
