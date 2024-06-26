#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M, K;
set<int> adjList[500001];
set<int> adjListR[500001]; // Sorted from least to greatest
int minVal = (1<<30);
vector<int> s;
bool done = false;
bool seen[500001];

void DFS1(int u) {
    if (seen[u]) return;
    seen[u] = true;
    minVal = min(minVal, u);
    for (auto v: adjListR[u]) {
        DFS1(v);
    }
}

void DFS2(int u) {
    if (seen[u] || done) return;
    seen[u] = true;
    s.push_back(u);
    if (u == K) {
        done = true;
        return;
    }
    for (auto v: adjList[u]) {
        DFS2(v);
        if (done) return;
    }
    s.pop_back();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].insert(v);
        adjListR[v].insert(u); // Reversed Direction
    }
    DFS1(K); // Find minVal
    memset(seen, 0, sizeof(seen));
    DFS2(minVal); // Get Lexicographic Sequence
    cout << s.size() << "\n";
    for (auto v: s) {
        cout << v << " ";
    } cout << "\n";
}
