#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
int A[MAX_N + 5];
long long DP[2][MAX_N + 5]; // '0' = Use row operation, '1' = Use 2x2 row operation

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        DP[0][i] = LL_INF;
        DP[1][i] = LL_INF;
    }
    for (int i = 1; i <= N; i++) {
        DP[0][i] = min(DP[0][i], DP[0][i - 1] + 1);
        DP[0][i] = min(DP[0][i], DP[1][i - 1] + (A[i] > A[i - 1]));
        DP[1][i] = min(DP[1][i], DP[0][i - 1] + (A[i] + 1) / 2);
        DP[1][i] = min(DP[1][i], DP[1][i - 1] + (A[i] + 1) / 2);
        cout << DP[0][i] << " " << DP[1][i] << "\n";
    }
    cout << min(DP[0][N], DP[1][N]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
