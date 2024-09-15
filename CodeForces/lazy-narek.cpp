#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e3;

int T, N, M;
map<char, int> ind;
int add[6][MAX_N + 5];
int fin[6][MAX_N + 5];
int DP[6][MAX_N + 5];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= 5; j++) {
            add[j][i] = 0;
            DP[j][i] = -INF;
            int cur = j;
            for (int k = 1; k <= M; k++) {
                if (!ind[s[k - 1]]) continue;
                if (ind[s[k - 1]] == cur) {
                    add[j][i]++;
                    cur = (cur == 5 ? 1 : cur + 1);
                }
                else {
                    add[j][i]--;
                }
            }
            fin[j][i] = cur;
        }
    }
    for (int i = 1; i <= N; i++) {
        DP[1][i] = 0;
    }
    for (int i = 1; i <= 5; i++) {
        DP[i][N + 1] = -INF;
    }
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k <= 5; k++) {
                DP[fin[k][j]][i] = max(DP[fin[k][j]][i], DP[k][j] + add[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 5; i++) {
        ans = max(ans, DP[i][N + 1] - 2 * (i - 1));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ind['n'] = 1;
    ind['a'] = 2;
    ind['r'] = 3;
    ind['e'] = 4;
    ind['k'] = 5;
    cin >> T;
    while (T--) {
        solve();
    }
}
