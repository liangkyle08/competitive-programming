#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, N, M;
int A[105][105];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            A[i][j] = (s[j - 1] == '#');
        }
    }
    bool flag = false;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            int cnt = A[i][j] + A[i][j + 1] + A[i + 1][j] + A[i + 1][j + 1];
            if (cnt == 3) flag = true;
        }
    }
    cout << (flag ? "phineas" : "ferb") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
