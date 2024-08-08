#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 3e5;

int N, s, t;
int A[MAX_N + 5];
bool seen[MAX_N + 5];
bool comp[MAX_N + 5];
vector<pair<int, int>> adjList[MAX_N + 5];
vector<int> divi[MAX_N + 5];
bool T[MAX_N + 5];
int maxDist = INF;
pair<int, int> path;
vector<int> ans;
pair<int, int> prv[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i <= MAX_N; i++) {
        if (comp[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            comp[j] = true;
            divi[j].push_back(i);
        }
    }
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int j = 0; j < (int)divi[A[i]].size() - 1; j++) {
            for (int k = j + 1; k < (int)divi[A[i]].size(); k++) {
                adjList[divi[A[i]][j]].push_back({divi[A[i]][k], i});
                adjList[divi[A[i]][k]].push_back({divi[A[i]][j], i});
            }
        }
    }
    cin >> s >> t;
    if (s == t) {
        cout << 1 << "\n";
        cout << s << "\n";
        return 0;
    }
    for (auto &v: divi[A[t]]) {
        T[v] = true;
    }
    queue<pair<int, pair<int, int>>> q;
    for (auto &v: divi[A[s]]) {
        seen[v] = true;
        prv[v] = {-1, -1};
        q.push({v, {v, 0}});
    }
    while (!q.empty()) {
        int u = q.front().fi;
        int root = q.front().se.fi;
        int dist = q.front().se.se;
        q.pop();
        if (T[u] && dist < maxDist) {
            maxDist = dist;
            path = {root, u};
        }
        for (auto &[v, c]: adjList[u]) {
            if (seen[v]) continue;
            seen[v] = true;
            prv[v] = {u, c};
            q.push({v, {root, dist + 1}});
        }
    }
    if (maxDist == INF) {
        cout << -1 << "\n";
        return 0;
    }
    while (prv[path.se].fi != -1) {
        ans.push_back(prv[path.se].se);
        path.se = prv[path.se].fi;
    }
    reverse(ans.begin(), ans.end());
    cout << maxDist + 2 << "\n";
    cout << s << " ";
    for (auto v: ans) {
        cout << v << " ";
    }
    cout << t << "\n";
}
