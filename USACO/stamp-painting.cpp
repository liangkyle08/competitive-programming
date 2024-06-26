#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M, K;
long long DP[1000001];

int main() {
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    cin >> N >> M >> K;
    DP[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (i < K) {
            DP[i] = (M*(DP[i-1])+M) % MOD;
        }
        else {
            DP[i] = (M*DP[i-1]+MOD-((M-1)*DP[i-K]) % MOD) % MOD;
        }
    }
    long long ans = 1;
    for (int i = 1; i <= N; i++) ans = (M*ans) % MOD;
    cout << (ans+MOD-DP[N]+DP[N-1]) % MOD;
}
