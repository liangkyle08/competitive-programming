#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
int A[4][MAX_N+5];
vector<array<int, 3>> pos = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1}
};

void solve() {
    cin >> N;
    long long total = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            total += A[i][j];
        }
    }
    int upperBound = ((total / 3) + 2) / 3;
    vector<pair<int, int>> ans(3, {-1, -1});
    bool flag = true;
    for (auto [a, b, c]: pos) {
        ans[a - 1].fi = 1;
        ans[a - 1].se = N;
        long long sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += A[a][i];
            if (sum >= upperBound) {
                ans[a - 1].se = i;
                break;
            }
        }
        ans[c - 1].fi = 1;
        ans[c - 1].se = N;
        sum = 0;
        for (int i = N; i >= 1; i--) {
            sum += A[c][i];
            if (sum >= upperBound) {
                ans[c - 1].fi = i;
                break;
            }
        }
        if (ans[c - 1].fi - ans[a - 1].se <= 1) continue;
        sum = 0;
        for (int i = ans[a - 1].se + 1; i <= ans[c - 1].fi - 1; i++) {
            sum += A[b][i];
        }
        if (sum < upperBound) continue;
        ans[b - 1].fi = ans[a - 1].se + 1;
        ans[b - 1].se = ans[c - 1].fi - 1;
        flag = false;
        break;
    }
    if (flag) {
        cout << -1 << "\n";
        return;
    }
    for (auto pi: ans) {
        cout << pi.fi << " " << pi.se << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
