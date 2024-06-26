#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
string s1, s2;
vector<int> adjList[53];
int inDegree[53];
set<int> outDegree[53];
bool seen[53];
bool isCycle;
int compSize;

int convert(char c) {
    if ('a' <= c && c <= 'z') return c-'a'+1;
    return c-'A'+27;
}

void DFS(int u) {
    if (seen[u]) return;
    seen[u] = true;
    if (inDegree[u] != 1) {
        isCycle = false;
    }
    compSize++;
    for (auto v: adjList[u]) {
        DFS(v);
    }
}

void solve() {
    for (int i = 1; i <= 52; i++) {
        adjList[i].clear();
        seen[i] = false;
        inDegree[i] = 0;
        outDegree[i].clear();
    }
    cin >> s1 >> s2;
    N = (int)s1.size();
    bool flag = false;
    set<int> s;
    for (int i = 0; i < N; i++) {
        int u = convert(s1[i]);
        int v = convert(s2[i]);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        outDegree[u].insert(v);
        if (u != v) {
            flag = true;
        }
        s.insert(v);
    }
    if (flag && (int)s.size() == 52) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for (int i = 1; i <= 52; i++) {
        ans += (int)outDegree[i].size();
        if (outDegree[i].find(i) != outDegree[i].end()) {
            ans--;
        }
        if ((int)outDegree[i].size() >= 2) {
            cout << -1 << '\n';
            return;
        }
        for (auto v: outDegree[i]) {
            inDegree[v]++;
        }
    }
    for (int i = 1; i <= 52; i++) {
        if (seen[i]) continue;
        compSize = 0;
        isCycle = true;
        DFS(i);
        if (compSize <= 1) isCycle = false;
        ans += isCycle;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
