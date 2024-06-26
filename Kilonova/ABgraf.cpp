#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
vector<int> adjList[200001];
int type[200001];
int Parent[200001];
int sz[200001];
int cnt[2]; // Count of # of A and B components
bool pos;

int Find(int x) {
    if (x == Parent[x]) {
        return x;
    }
    Parent[x] = Find(Parent[x]);
    return Parent[x];
}

void Union(int a, int b) {
    if (a == b) return;
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    Parent[b] = a;
    sz[a] += sz[b];
}

void DFS(int node, int parent) {
    set<int> s;
    for (auto child: adjList[node]) {
        if (type[child] == type[node]) {
            continue;
        }
        s.insert(Parent[child]);
    }
    if ((int)s.size() == cnt[!type[node]]
        || (sz[Parent[node]] == 1 && cnt[type[node]] == 2)) {
        pos = true;
    }
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
    }
}

void solve() {
    cin >> N >> M;
    string s;
    cin >> s;
    for (int i = 1; i <= N; i++) {
        type[i] = (s[i-1] == 'A');
        Parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        if (type[u] == type[v]) {
            Union(Find(u), Find(v));
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i == Parent[i]) {
            cnt[type[i]]++;
        }
    }
    pos = false;
    DFS(1, -1);
    if (pos) {
        cout << "DA\n";
    }
    else {
        cout << "NU\n";
    }
    for (int i = 1; i <= N; i++) {
        adjList[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
