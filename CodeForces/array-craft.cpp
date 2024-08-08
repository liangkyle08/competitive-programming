#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

int T, N, X, Y;

void solve() {
    cin >> N >> X >> Y;
    vector<int> A(N + 1, -1);
    for (int i = min(X, Y); i <= max(X, Y); i++) {
        A[i] = 1;
    }
    for (int i = min(X, Y) - 2; i >= 1; i -= 2) {
        A[i] = 1;
    }
    for (int i = max(X, Y) + 2; i <= N; i += 2) {
        A[i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        cout << A[i] << " ";
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
