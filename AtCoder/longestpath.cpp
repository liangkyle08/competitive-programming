#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adjList[100001];
int inDegree[100001];
int DP[100001];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        inDegree[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: adjList[u]) {
            inDegree[v]--;
            DP[v] = max(DP[v], DP[u]+1);
            ans = max(ans, DP[v]);
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << ans << "\n";
}