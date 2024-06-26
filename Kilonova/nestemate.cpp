#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, A, B;
int X[100001];
int Y[100001];
int Z[100001];

void solve() {
    cin >> N >> A >> B;
    vector<vector<int>> ind(500001, vector<int>());
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        ind[X[i]].push_back(i);
        ind[Y[i]].push_back(i);
        ind[Z[i]].push_back(i);
    }
    vector<int> minDist(N+1, (1<<30));
    map<int, int> seenColor;
    queue<int> q;
    q.push(A);
    minDist[A] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == B) break;
        if (!seenColor[X[u]]) {
            seenColor[X[u]] = true;
            for (auto v: ind[X[u]]) {
                if (minDist[v] == (1<<30)) {
                    minDist[v] = minDist[u]+1;
                    q.push(v);
                }
            }
        }
        if (!seenColor[Y[u]]) {
            seenColor[Y[u]] = true;
            for (auto v: ind[Y[u]]) {
                if (minDist[v] == (1<<30)) {
                    minDist[v] = minDist[u]+1;
                    q.push(v);
                }
            }
        }
        if (!seenColor[Z[u]]) {
            seenColor[Z[u]] = true;
            for (auto v: ind[Z[u]]) {
                if (minDist[v] == (1 << 30)) {
                    minDist[v] = minDist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    cout << (minDist[B] == (1<<30) ? -1 : minDist[B]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nestemate.in", "r", stdin);
    freopen("nestemate.out", "w", stdout);
    cin >> T;
    while (T--) {
        solve();
    }
}
