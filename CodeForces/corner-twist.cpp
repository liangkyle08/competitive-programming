#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

int T, N, M;
int A[501][501];
int B[501][501];

void solve() {
    cin >> N >> M;
    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= M; j++) {
            A[i][j] = s[j-1] - '0';
        }
    }
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= M; j++) {
            B[i][j] = s[j-1] - '0';
        }
    }
    vector<int> row1(N+1), row2(N+1), col1(M+1), col2(M+1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            row1[i] = (row1[i] + A[i][j]) % 3;
            row2[i] = (row2[i] + B[i][j]) % 3;
            col1[j] = (col1[j] + A[i][j]) % 3;
            col2[j] = (col2[j] + B[i][j]) % 3;
        }
    }
    bool ans = true;
    for (int i = 1; i <= N; i++) {
        if (row1[i] == row2[i]) continue;
        ans = false;
    }
    for (int j = 1; j <= M; j++) {
        if (col1[j] == col2[j]) continue;
        ans = false;
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
