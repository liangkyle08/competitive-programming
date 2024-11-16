#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
int P[MAX_N + 5];
vector<int> comp;
int curComp;

void DFS(int node) {
    if (comp[node]) {
        return;
    }
    comp[node] = curComp;
    DFS(P[node]);
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    comp.clear();
    comp.resize(N + 5);
    curComp = 0;
    for (int i = 1; i <= N; i++) {
        if (comp[i]) continue;
        curComp++;
        DFS(i);
    }
    int ans = N - curComp;
    for (int i = 1; i < N; i++) {
        if (comp[i] != comp[i + 1]) continue;
        cout << ans - 1 << "\n";
        return;
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
