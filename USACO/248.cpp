#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int MAX_N = 248;

int N;
int A[MAX_N + 5];
int DP[MAX_N + 5][MAX_N + 45]; // At the "i" position, with value of "j", the maximum value;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("248.in", "r", stdin);
    //freopen("248.out", "w", stdout);
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        ans = max(ans, A[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= MAX_N + 45; j++) {
            DP[i][j] = max(DP[i][j], DP[i - 1][j])
        }
    }
    cout << ans << "\n";
}
