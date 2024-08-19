#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 5e5;

int N, M;
vector<int> adjList[MAX_N + 5];
bool seen[MAX_N + 5];

void BFS() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v: adjList[u]) {
            q.push(v);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    // memset(seen, false, sizeof(seen));
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    BFS();
}
