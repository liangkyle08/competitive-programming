// OJI 2019 XI-XII: Problema 1
// Conexidad (Connection)
// https://kilonova.ro/problems/20

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int N, M;
vector<int> adjList[101];
int connectComp[101];
int sz[101];
vector<int> components[101];

void DFS(int u, int curComp) {
    if (!connectComp[u]) {
        connectComp[u] = curComp;
        sz[curComp]++;
        components[curComp].push_back(u);
        for (auto v: adjList[u]) {
            DFS(v, curComp);
        }
    }
}

int main() {
    freopen("conexidad.in", "r", stdin);
    freopen("conexidad.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int numComp = 0;
    for (int i = 1; i <= N; i++) {
        if (!connectComp[i]) {
            numComp++;
            DFS(i, numComp);
        }
    }
    vector<pair<int, int>> ans;
    priority_queue<pair<int, int>> q1, q2; // q1 starts with max component, q2 everything else
    int maxSize = -1;
    int maxComp = -1;
    for (int i = 1; i <= numComp; i++) {
        if (sz[i] > maxSize) {
            maxSize = sz[i];
            maxComp = i;
        }
    }
    for (int i = 1; i <= numComp; i++) {
        if (i == maxComp) {
            q1.emplace(sz[i], i);
            continue;
        }
        q2.emplace(sz[i], i);
    }
    while (!q2.empty()) {
        int curSize = q1.top().f;
        int curComp = q1.top().s;
        q1.pop();
        if (curSize == 0) {
            break;
        }
        int cnt = 0;
        for (int i = 1; i <= curSize; i++) {
            if (q2.empty()) break;
            int nextSize = q2.top().f;
            int nextComp = q2.top().s;
            q2.pop();
            nextSize--;
            cnt++;
            ans.emplace_back(curComp, nextComp);
            q1.emplace(nextSize, nextComp);
        }
        q1.emplace((curSize-cnt), curComp);
    }
    if (!q2.empty()) {
        cout << 2 << "\n";
        while (!q2.empty()) {
            int curSize = q1.top().f;
            int curComp = q1.top().s;
            q1.pop();
            bool flag = false;
            if (curSize == 0) {
                flag = true;
                curSize = 1;
            }
            int cnt = 0;
            for (int i = 1; i <= curSize; i++) {
                if (q2.empty()) break;
                int nextSize = q2.top().f;
                int nextComp = q2.top().s;
                q2.pop();
                nextSize--;
                cnt++;
                ans.emplace_back(curComp, nextComp);
                q1.emplace(nextSize, nextComp);
            }
            if (!flag) {
                q1.emplace((curSize-cnt), curComp);
            }
        }
    }
    else {
        cout << 1 << "\n";
    }
    cout << ans.size() << "\n";
    vector<int> curInd(numComp+1);
    for (auto [u, v]: ans) {
        cout << components[u][curInd[u]] << " " << components[v][curInd[v]] << "\n";
        curInd[u] = (curInd[u]+1) % sz[u];
        curInd[v] = (curInd[v]+1) % sz[v];
    }
}
