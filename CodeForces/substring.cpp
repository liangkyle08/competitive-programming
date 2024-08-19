#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 3e5;

int N, M;
string s;
vector<int> adjList[MAX_N + 5];
int in[MAX_N + 5];
int val[MAX_N + 5];
int DP[ALP + 5][MAX_N + 5];
bool seen[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> s;
    for (int i = 1; i <= N; i++) {
        val[i] = (s[i - 1] - 'a') + 1;
    }
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in[i]) continue;
        q.push(i);
    }
    bool flag = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (seen[u]) {
            flag = false;
            break;
        }
        seen[u] = true;
        DP[val[u]][u]++;
        for (auto &v: adjList[u]) {
            in[v]--;
            for (int i = 1; i <= ALP; i++) {
                DP[i][v] = max(DP[i][v], DP[i][u]);
            }
            if (in[v]) continue;
            q.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        flag &= seen[i];
        for (int j = 1; j <= ALP; j++) {
            ans = max(ans, DP[j][i]);
        }
    }
    cout << (flag ? ans : -1) << "\n";
}
