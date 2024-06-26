#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int parent[1001];
int sz[1001];
long long X[1001];
long long Y[1001];

int Find(int x) {
    if (x == parent[x]) {
        return x;
    }
    parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int a, int b) {
    if (a == b) return;
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        parent[i] = i;
        sz[i] = 1;
    }
    vector<pair<long long, pair<int, int>>> edges;
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            edges.push_back({(long long)powl(X[i]-X[j], 2)+(long long)powl(Y[i]-Y[j], 2), {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    long long ans = 0LL;
    for (auto [len, edge]: edges) {
        ans = max(ans, len);
        Union(Find(edge.fi), Find(edge.se));
        if (sz[Find(edge.fi)] == N || sz[Find(edge.se)] == N) break;
    }
    cout << ans << "\n";
}