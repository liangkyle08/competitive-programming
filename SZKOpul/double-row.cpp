#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int MAX_N = 5e4+5;

int N;
int X[MAX_N];
int Y[MAX_N];
vector<pair<int, bool>> adjList[MAX_N];
int seen[MAX_N];
bool flip[MAX_N];

int DFS(int u, int cnt, int T) {
    seen[u] = T;
    for (auto [v, t]: adjList[u]) {
        if (seen[v] == T) continue;
        if (flip[u] ^ t) {
            cnt++;
            flip[v] = true;
        }
        seen[v] = T;
        cnt = DFS(v, cnt, T);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int MAX_VAL = 0;
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
        MAX_VAL = max(MAX_VAL, X[i]);
    }
    for (int i = 1; i <= N; i++) {
        cin >> Y[i];
        MAX_VAL = max(MAX_VAL, Y[i]);
    }
    vector<int> ind(MAX_VAL+1);
    vector<int> tp(MAX_VAL+1);
    for (int i = 1; i <= N; i++) {
        if (ind[X[i]] != 0) {
            adjList[ind[X[i]]].push_back({i, tp[X[i]] == 1});
            adjList[i].push_back({ind[X[i]], tp[X[i]] == 1});
        }
        if (ind[Y[i]] != 0) {
            adjList[ind[Y[i]]].push_back({i, tp[Y[i]] == 2});
            adjList[i].push_back({ind[Y[i]], tp[Y[i]] == 2});
        }
        ind[X[i]] = i;
        tp[X[i]] = 1;
        ind[Y[i]] = i;
        tp[Y[i]] = 2;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (seen[i] > 0) continue;
        memset(flip, false, sizeof(flip));
        int cnt1 = DFS(i, 0, 1);
        memset(flip, false, sizeof(flip));
        flip[i] = true;
        int cnt2 = DFS(i, 1, 2);
        ans += min(cnt1, cnt2);
    }
    cout << ans << "\n";
}
