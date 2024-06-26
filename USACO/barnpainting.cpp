#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int color[100001];
long long DP[4][100001];
vector<int> adjList[100001];

void DFS(int node, int parent) {
    vector<bool> imp(4);
    if (color[node]) {
        DP[color[node]][node] = 1;
    }
    else {
        for (int i = 1; i <= 3; i++) {
            DP[i][node] = 1;
        }
    }
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        imp[color[child]] = true;
        if (color[child]) {
            for (int i = 1; i <= 3; i++) {
                if (i == color[child]) continue;
                DP[i][node] = (DP[i][node]*DP[color[child]][child]) % MOD;
            }

        }
        else {
            for (int i = 1; i <= 3; i++) {
                long long sum = 0;
                for (int j = 1; j <= 3; j++) {
                    if (i == j) continue;
                    sum += DP[j][child];
                }
                DP[i][node] = (DP[i][node]*sum) % MOD;
            }
        }
    }
    for (int i = 1; i <= 3; i++) {
        if (imp[i] || (color[node] && i != color[node])) {
            DP[i][node] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 1; i <= K; i++) {
        int b, c;
        cin >> b >> c;
        color[b] = c;
    }
    DFS(1, -1);
    long long ans = 0;
    for (int i = 1; i <= 3; i++) {
        ans = (ans+DP[i][1]) % MOD;
    }
    cout << ans << "\n";
}
