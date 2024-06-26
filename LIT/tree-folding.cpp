#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, Q;
vector<int> adjList[300001];
int nextPow;

void BFS(vector<int> inDegree) {
    queue<int> q;
    vector<int> val(nextPow+1);
    for (int i = 1; i <= nextPow; i++) {
        if (inDegree[i] == 1) {
            q.push(i);
        }
    }
    bool pos = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: adjList[u]) {
            if (!inDegree[v]) continue;
            if (val[u] == val[v]) {
                val[v]++;
                inDegree[u]--;
                inDegree[v]--;
                if (inDegree[v] == 1) {
                    q.push(v);
                }
                break;
            }
            else {
                pos = false;
            }
        }
    }
    if (pos) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

void solve() {
    cin >> Q;
    for (int i = 1; i <= 300000; i++) {
        adjList[i].clear();
    }
    vector<int> inDegree(Q+2);
    nextPow = 2;
    for (int u = 2; u <= Q+1; u++) {
        int v;
        cin >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        inDegree[u]++;
        inDegree[v]++;
        if (u == nextPow) {
            BFS(inDegree);
            nextPow *= 2;
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}

