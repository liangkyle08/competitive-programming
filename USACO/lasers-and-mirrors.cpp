#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
pair<int, int> edges[100005];
vector<pair<int, bool>> adjList[100005];
int DP[100005];
bool seen[100005];

int main() {
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> edges[0].fi >> edges[0].se >> edges[N+1].fi >> edges[N+1].se;
    for (int i = 1; i <= N; i++) {
        cin >> edges[i].fi >> edges[i].se;
    }
    map<int, vector<int>> row;
    map<int, vector<int>> col;
    for (int i = 0; i <= N+1; i++) {
        DP[i] = (1<<30);
        row[edges[i].fi].push_back(i);
        col[edges[i].se].push_back(i);
    }
    DP[0] = 0;
    for (auto &[temp, s]: row) {
        sort(s.begin(), s.end());
        for (int i = 0; i < (int)s.size()-1; i++) {
            adjList[s[i]].push_back({s[i+1], false});
            adjList[s[i+1]].push_back({s[i], false});
        }
    }
    for (auto &[temp, s]: col) {
        sort(s.begin(), s.end());
        for (int i = 0; i < (int)s.size()-1; i++) {
            adjList[s[i]].push_back({s[i+1], true});
            adjList[s[i+1]].push_back({s[i], true});
        }
    }
    queue<pair<int, bool>> q;
    q.push({0, false});
    seen[0] = true;
    while (!q.empty()) {
        int u = q.front().fi;
        bool curDir = q.front().se;
        q.pop();
        for (auto [v, newDir]: adjList[u]) {
            if (seen[v]) continue;
            seen[v] = true;
            if (u != 0) DP[v] = DP[u]+(curDir != newDir);
            else DP[v] = DP[u];
            q.push({v, newDir});
        }
    }
    cout << DP[N+1] << "\n";
}
