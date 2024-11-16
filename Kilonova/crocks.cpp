#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const uint64_t MOD = 1e9 + 7;
const int MAX_N = 1e6;

int N;
uint64_t A[MAX_N + 5];

uint64_t add(uint64_t a, uint64_t b) {
    return (a + b) % MOD;
}

uint64_t mul(uint64_t a, uint64_t b) {
    return (a * b) % MOD;
}

uint64_t exp(uint64_t a, int p) {
    a %= MOD;
    uint64_t result = 1LL;
    while (p > 0) {
        if (p % 2 == 1) result = mul(result, a);
        a = mul(a, a);
        p /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    uint64_t S1 = 0;
    uint64_t S2 = 0;
    uint64_t S3 = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S1 = add(S1, A[i]);
        S2 = add(S2, exp(A[i], 2));
        S3 = add(S3, exp(A[i], 3));
    }
    uint64_t ans = ((exp(S1, 3) - mul(3, mul(S1, S2)) + mul(2, S3)) * exp(6, MOD - 2)) % MOD;
    cout << ans << "\n";
}
