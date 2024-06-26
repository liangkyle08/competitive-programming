// USACO 2016 February Contest, Gold
// Problem 2. Circular Barn Revisited
// http://www.usaco.org/index.php?page=viewproblem2&cpid=622

#include <bits/stdc++.h>
using namespace std;

int N, K;
long long cows[101];
long long DP[8][101];

int main() {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        memset(DP, 63, sizeof(DP));
        DP[0][N] = 0;
        for (int k = 1; k <= K; k++) {
            for (int j = 0; j < N; j++) {
                long long val = 0;
                for (int a = j+1; a <= N; a++) {
                    val += cows[a-1]*(a-j-1);
                    DP[k][j] = min(DP[k][j], val+DP[k-1][a]);
                }
            }
        }
        ans = min(ans, DP[K][0]);
        rotate(cows, cows+1, cows+N);
    }
    cout << ans << "\n";
}
