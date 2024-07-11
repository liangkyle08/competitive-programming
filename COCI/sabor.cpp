#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int N;
int T[MAX_N+5];
int cnt[MAX_N+5];
vector<int> adjList[MAX_N+5];

void DFS(int u) {
    for (auto v: adjList[u]) {
        if (T[u] == T[v]) {
            cnt[u]--;
            cnt[v]--;
        }
        else {
            cnt[u]++;
            cnt[v]++;
        }
    }
    T[u] = !T[u];
    for (auto v: adjList[u]) {
        if (cnt[v] <= 2) continue;
        DFS(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= 5; i++) {
        int P;
        cin >> P;
        while (P--) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            cnt[u]++;
            cnt[v]++;
        }
    }
    memset(T, false, sizeof(T));
    for (int i = 1; i <= N; i++) {
        if (cnt[i] <= 2) continue;
        DFS(i);
    }
    for (int i = 1; i <= N; i++) {
        cout << (T[i] ? 'A' : 'B');
    } cout << "\n";
}
