#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
vector<pair<int, int>> adjList[100001];
int seen[100001];
bool flag;
vector<int> cur;

void DFS(int u, int X) {
    if (seen[u] == 1) {
        flag = false;
        return;
    }
    seen[u] = 1;
    for (auto [v, state]: adjList[u]) {
        if (state > X) continue;
        DFS(v, X);
    }
    seen[u] = 2;
}

bool check(int X) {
    flag = true;
    for (int i = 1; i <= N; i++) seen[i] = 0;
    for (int i = 1; i <= N; i++) {
        if (!seen[i]) {
            DFS(i, X);
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int m;
        cin >> m;
        vector<int> A(m+1);
        for (int j = 1; j <= m; j++) {
            cin >> A[j];
            if (j > 1) {
                adjList[A[j-1]].push_back({A[j], i});
            }
        }
    }
    int low = 0;
    int high = M;
    while (low < high) {
        int mid = (low+high+1)/2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid-1;
        }
    }
    vector<int> ans;
    vector<int> inDegree(N+1);
    for (int i = 1; i <= N; i++) seen[i] = 0;
    for (int i = 1; i <= N; i++) {
        for (auto [v, state]: adjList[i]) {
            if (state > low) continue;
            inDegree[v]++;
        }
    }
    priority_queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(-i);
        }
    }
    while (!q.empty()) {
        int u = -q.top();
        q.pop();
        ans.push_back(u);
        for (auto [v, state]: adjList[u]) {
            if (state > low) continue;
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(-v);
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        cout << ((i < (int)ans.size()-1) ? " " : "\n");
    }
}
