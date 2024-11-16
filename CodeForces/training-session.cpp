#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
int A[MAX_N + 5];
int B[MAX_N + 5];
int aCnt[MAX_N + 5];
int bCnt[MAX_N + 5];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        aCnt[A[i]]++;
        bCnt[B[i]]++;
    }
    long long ans = 1LL * N * (N - 1) * (N - 2) / 6;
    for (int i = 1; i <= N; i++) {
        ans -= 1LL * (aCnt[A[i]] - 1) * (bCnt[B[i]] - 1);
    }
    cout << ans << "\n";
    for (int i = 1; i <= N; i++) {
        aCnt[A[i]]--;
        bCnt[B[i]]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
