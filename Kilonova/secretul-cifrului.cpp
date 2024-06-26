#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 19997;

int N, K;
long long DP[2001];

long long factorial(int x) {
    if (x <= 1) return 1;
    return (x*factorial(x-1)) % MOD;
}

int main() {
    cin >> N >> K;
    vector<int> factors;
    for (int i = 1; i <= min(N, K); i++) {
        if (K % i == 0) {
            factors.push_back(i);
        }
    }
    DP[0] = 1;
    for (int i = 0; i <= N; i++) {
        if (DP[i]) {
            for (auto v: factors) {
                if (i+v > N) continue;
                if (v == 1) {
                    DP[i+v] = (DP[i+v]+DP[i]) % MOD;
                }
                else {
                    DP[i+v] += (2*(DP[i+v]+DP[i]) % MOD) % MOD;
                }
            }
        }
    }
    cout << (DP[N]*N) % MOD << "\n";
}
