#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 998244353;

int N;
int A[3001];
int B[3001];
long long DP[3001][3001];
long long prefixSums[3001][3001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    DP[0][0] = 1;
    for (int i = 0; i <= N; i++) {
        if (i > 0) {
            for (int j = A[i]; j <= B[i]; j++) {
                DP[i][j] = prefixSums[i-1][j];
            }
        }
        for (int j = 0; j <= 3000; j++) {
            if (j > 0) {
                prefixSums[i][j] = prefixSums[i][j-1];
            }
            prefixSums[i][j] = (prefixSums[i][j]+DP[i][j]) % MOD;
        }
    }
    long long ans = 0;
    for (int i = A[N]; i <= B[N]; i++) {
        ans = (ans+DP[N][i]) % MOD;
    }
    cout << ans << "\n";
}
