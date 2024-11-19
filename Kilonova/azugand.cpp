#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;
const int MAX_V = 20;

int N, Q;
int V[MAX_N + 5];
bool adj[MAX_V + 5][MAX_V + 5];

bool get_bit(int &x, int &pos) { return (x >> pos) & 1;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
        for (int j = 0; j < MAX_V; j++) {
            for (int k = j + 1; k < MAX_V; k++) {
                if (!get_bit(V[i], j) || !get_bit(V[i], k)) continue;
                adj[j][k] = true;
                adj[k][j] = true;
            }
        }
    }
    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        queue<pair<int, int>> q;
        for (int i = 0; i < MAX_V; i++) {
            if (!get_bit(V[X], i)) continue;
            q.push({i, 0});
        }
        vector<int> minDist(MAX_V + 5, INF);
        while (!q.empty()) {
            int u = q.front().fi;
            int depth = q.front().se;
            q.pop();
            if (minDist[u] != INF) continue;
            minDist[u] = depth + 1;
            for (int v = 0; v < MAX_V; v++) {
                if (!adj[u][v]) continue;
                q.push({v, minDist[u]});
            }
        }
        int ans = INF;
        for (int i = 0; i < MAX_V; i++) {
            if (!get_bit(V[Y], i)) continue;
            ans = min(ans, minDist[i]);
        }
        cout << (ans == INF ? -1 : ans) << "\n";
    }
}
