#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N, Q;
int A[MAX_N + 5];
map<string, int> val;
set<int> ind[7];

void query() {
    int X, Y;
    cin >> X >> Y;
    if (A[X] > A[Y]) swap(X, Y);
    if (!((A[X] == 1 && A[Y] == 6)
        || (A[X] == 2 && A[Y] == 5)
        || (A[X] == 3 && A[Y] == 4))) {
        cout << abs(X - Y) << "\n";
        return;
    }
    int ans = INF;
    for (int v = 1; v <= 6; v++) {
        if (v == A[X] || v == A[Y]) continue;
        int cur = *ind[v].lower_bound(X);
        if (cur != INF) {
            ans = min(ans, abs(X - cur) + abs(Y - cur));
        }
        cur = *ind[v].lower_bound(Y);
        if (cur != INF) {
            ans = min(ans, abs(X - cur) + abs(Y - cur));
        }
        cur = *(--ind[v].lower_bound(X));
        if (cur != -INF) {
            ans = min(ans, abs(X - cur) + abs(Y - cur));
        }
        cur = *(--ind[v].lower_bound(Y));
        if (cur != -INF) {
            ans = min(ans, abs(X - cur) + abs(Y - cur));
        }
    }
    cout << (ans == INF ? -1 : ans) << "\n";
}

void solve() {
    for (int i = 1; i <= 6; i++) {
        ind[i].clear();
        ind[i].insert(-INF);
        ind[i].insert(INF);
    }
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        A[i] = val[s];
        ind[A[i]].insert(i);
    }
    while (Q--) {
        query();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    val["BG"] = 1;
    val["BR"] = 2;
    val["BY"] = 3;
    val["GR"] = 4;
    val["GY"] = 5;
    val["RY"] = 6;
    cin >> T;
    while (T--) {
        solve();
    }
}
