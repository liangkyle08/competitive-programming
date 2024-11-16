#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 998244353;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e6;

int N, K;
vector<int> A[MAX_N + 5];
int cnt[MAX_N + 5];
int inv[MAX_N + 5];

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int power(int a, int b) {
    int cur = 1;
    while (b > 0) {
        if (b & 1) cur = mul(cur, a);
        a = mul(a, a);
        b >>= 1;
    }
    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        A[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> A[i][j];
            cnt[A[i][j]]++;
        }
    }
    for (int i = 0; i <= MAX_N; i++) {
        inv[i] = power(i, MOD - 2);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (auto &v: A[i]) {
            ans = add(ans, mul(mul(inv[N], inv[(int)A[i].size()]), mul(cnt[v], inv[N])));
        }
    }
    cout << ans << "\n";
}
