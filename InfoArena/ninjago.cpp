#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
vector<pair<pair<long long, int>, int>> adjList[31201]; // cost, number of "E"s, node
vector<pair<pair<int, long long>, pair<int, int>>> edges;
int parent[31201];
int sz[31201];
bool seen[31201];

int DFS1(int u, int depth) {
    if (!seen[u]) {
        seen[u] = true;
        depth++;
        for (auto [pi, v]: adjList[u]) {
            if (!pi.se) {
                depth = DFS1(v, depth);
            }
        }
    }
    return depth;
}

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

long long MST() {
    long long ans = 0;
    for (auto [pi1, pi2]: edges) {
        int u = pi2.fi;
        int v = pi2.se;
        long long c = pi1.se;
        if (Find(u) != Find(v)) {
            Union(Find(u), Find(v));
            ans += c;
        }
    }
    return ans;
}

pair<int, int> MST2() {
    int cnt = 0;
    int cost = 0;
    for (auto [pi1, pi2]: edges) {
        int u = pi2.fi;
        int v = pi2.se;
        if (Find(u) != Find(v)) {
            Union(Find(u), Find(v));
            if (pi1.fi > 0) {
                cnt++;
                cost += pi1.fi;
            }
        }
    }
    return {cost, cnt};
}

int main() {
    freopen("ninjago.in", "r", stdin);
    freopen("ninjago.out", "w", stdout);
    cin >> T >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        long long c = 0LL;
        int cnt = 0;
        for (int j = 0; j < 4; j++){
            c += (long long)powl(5, j)*((s[j]-'A'+1) % 5);
            if (s[j] == 'E') cnt++;
        }
        adjList[u].push_back({{c, cnt}, v});
        adjList[v].push_back({{c, cnt}, u});
        edges.push_back({{cnt, c}, {u, v}});
    }
    if (T == 1) {
        cout << DFS1(1, 0) << "\n";
    }
    else {
        sort(edges.begin(), edges.end());
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        if (T == 3) {
            cout << MST() << "\n";
        }
        else {
            pair<int, int> pi = MST2();
            cout << pi.se << "\n";
            cout << pi.fi << "\n";
        }
    }
}
