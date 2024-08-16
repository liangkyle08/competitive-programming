#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N, S;
int A[MAX_N + 5];
long long X[MAX_N + 5];
long long Y[MAX_N + 5];
long long DP[2][MAX_N + 5]; // 0 = minimize 'X', 1 = minimize 'Y'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> S;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            if (i == 1 || i == N) {
                X[i] = A[i];
                Y[i] = A[i];
                continue;
            }
            if (A[i] <= S) {
                X[i] = 0;
                Y[i] = A[i];
            }
            else {
                X[i] = S;
                Y[i] = A[i] - S;
            }
        }
        DP[0][1] = 0;
        DP[1][1] = 0;
        for (int i = 2; i <= N; i++) {
            DP[0][i] = min(DP[0][i - 1] + Y[i - 1] * X[i],
                           DP[1][i - 1] + X[i - 1] * X[i]);
            DP[1][i] = min(DP[0][i - 1] + Y[i - 1] * Y[i],
                           DP[1][i - 1] + X[i - 1] * Y[i]);
        }
        cout << DP[0][N] << "\n";
    }
}
