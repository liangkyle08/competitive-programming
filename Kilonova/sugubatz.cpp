#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e6;

int N, X;
int A[MAX_N+1];
int B[MAX_N+1];
int seen[MAX_N+1];
int val[MAX_N+1];

void sieve() {
    for (int i = 2; i <= MAX_N; i++) {
        int cnt = 0;
        for (int j = i; j <= MAX_N; j += i) {
            cnt += seen[j];
        }
        for (int j = i; j <= MAX_N; j += i) {
            if (!seen[j] || cnt <= 1) continue;
            val[j] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        seen[A[i]]++;
    }
    sieve();
    for (int i = 1; i <= N; i++) {
        B[i] = max(val[A[i]], 1);
    }
    vector<int> cnt(32);
    int cur = 0;
    long long ans = 0;
    int L = 0;
    int R = 0;
    while (L <= N && R <= N) {
        if (cur >= X) {
            L++;
            ans += N-R+1;
            for (int j = 0; j < 32; j++) {
                cnt[j] -= (B[L]>>j) & 1;
                if (cnt[j] == 0 && ((B[L]>>j) & 1)) {
                    cur -= (1<<j);
                }
            }
        }
        else {
            R++;
            for (int j = 0; j < 32; j++) {
                cnt[j] += (B[R]>>j) & 1;
                if (cnt[j] == 1 && ((B[R]>>j) & 1)) {
                    cur += (1<<j);
                }
            }
        }
    }
    cout << ans << "\n";
}
