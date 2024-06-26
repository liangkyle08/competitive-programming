#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
vector<int> adjList[200001];
set<int> nodes;
map<int, bool> seen;
vector<long long> comps;

void DFS(int u) {
    if (seen[u]) return;
    seen[u] = true;
    comps.back()++;
    for (auto v: adjList[u]) {
        DFS(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        nodes.insert(u);
        nodes.insert(v);
    }
    for (auto node: nodes) {
        if (!seen[node]) {
            comps.push_back(0LL);
            DFS(node);
        }
    }
    long long compSize = (long long)comps.size();
    sort(comps.begin(), comps.end());
    if (comps.size() > N) {
        vector<long long> temp(N);
        for (int i = 0; i < (int)comps.size(); i++) {
            temp[i % N] += comps[i];
        }
        comps.clear();
        comps.resize(N);
        for (int i = 0; i < N; i++) {
            comps[i] = temp[i];
        }
    }
    long long mx = *max_element(comps.begin(), comps.end());
    long long mxCnt = count(comps.begin(), comps.end(), mx);
    long long total = ((mx-1LL)*(long long)N+mxCnt)-(long long)nodes.size();
    cout << total+(long long)compSize-1LL << "\n";
}
