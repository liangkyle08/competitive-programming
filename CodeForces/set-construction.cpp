#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[101][101];
int in[101];


void solve() {
    cin >> N;
    vector<int> adjList[101];
    set<int> sets[101];
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            A[i][j] = (s[j-1]-'0');
            if (A[i][j]) {
                in[j]++;
                adjList[i].push_back(j);
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        sets[u].insert(u);
        for (auto &v: adjList[u]) {
            in[v]--;
            sets[v].insert(sets[u].begin(), sets[u].end());
            if (in[v] > 0) continue;
            q.push(v);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << sets[i].size() << " ";
        for (auto &v: sets[i]) {
            cout << v << " ";
        } cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
