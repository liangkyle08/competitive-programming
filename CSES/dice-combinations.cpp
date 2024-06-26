#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int N;
int DP[1000001];

int main() {
    cin >> N;
    DP[0] = 1;
    for (int i = 0; i <= N; i++) {
        if (DP[i] > 0) {
            for (int j = i+1; j <= min(i+6, N); j++) {
                DP[j] = (DP[j]+DP[i]) % MOD;
            }
        }
    }
    cout << DP[N] << "\n";
}
