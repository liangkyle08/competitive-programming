#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
long long C;
vector<long long> adjList[1001];
long long arr[1001];
long long DP[1001][1001]; // City, Day

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        memset(DP[i], -1, sizeof(DP[i]));
    }
    DP[1][0] = 0;
    for (int i = 1; i <= M; i++) {
        long long u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    long long ans = 0LL;
    for (int j = 1; j <= 1000; j++) {
        long long t = (long long)j;
        for (int u = 1; u <= N; u++) {
            if (DP[u][j-1] == -1) continue;
            for (auto v: adjList[u]) {
                DP[v][j] = max(DP[v][j], DP[u][j-1]+arr[v]);
                if (v == 1) {
                    ans = max(ans, DP[v][j]-C*t*t);
                }
            }
        }
    }
    cout << ans << "\n";
}
