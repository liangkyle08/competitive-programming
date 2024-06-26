#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
int parent[100001];
int sz[100001];
vector<array<int, 3>> edges;

int Find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    if (a == b) return;
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    sz[a] += sz[b];
    parent[b] = a;
}

int main() {
    freopen("transport2.in", "r", stdin);
    freopen("transport2.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
       int u, v, c;
       cin >> u >> v >> c;
       edges.push_back({-c, u, v});
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    for (auto [c, u, v]: edges) {
        if (Find(u) != Find(v)) {
            Union(Find(u), Find(v));
            if (Find(1) == Find(N)) {
                cout << -c << "\n";
                break;
            }
        }
    }
}
