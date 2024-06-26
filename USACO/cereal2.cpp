#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
vector<pair<int, int>> adjList[100001];
bool inDegree[100001];
bool seen[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back({v, i});
        inDegree[v] = true;
    }
    vector<int> ans;
    vector<bool> edgeSeen(N+1);
    queue<int> q;
    int total = 0;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i]) continue;
        q.push(i);
        int edgeCnt = 0;
        bool flag = false;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, e]: adjList[u]) {
                if (seen[v]) {
                    flag = true;
                    continue;
                }
                seen[v] = true;
                q.push(v);
                edgeCnt++;
                edgeSeen[e] = true;
                ans.push_back(e);
            }
        }
        total += edgeCnt+flag;
    }
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        q.push(i);
        int edgeCnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, e]: adjList[u]) {
                if (seen[v]) continue;
                seen[v] = true;
                q.push(v);
                edgeCnt++;
                edgeSeen[e] = true;
                ans.push_back(e);
            }
        }
        total += edgeCnt;
    }
    cout << N-total << "\n";
    for (int i = 1; i <= N; i++) {
        if (edgeSeen[i]) continue;
        ans.push_back(i);
    }
    for (auto v: ans) {
        cout << v << "\n";
    }
}
