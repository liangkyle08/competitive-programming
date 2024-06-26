#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long long A[100001];
int nxt[100001];
int prv[100001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    nxt[N] = N+1;
    int curMax = A[N]-N+1;
    int curInd = N;
    for (int i = N-1; i >= 1; i--) {
        nxt[i] = curInd;
        if (A[i]-i+1 >= curMax) {
            curMax = A[i]-i+1;
            curInd = i;
        }
    }
    prv[1] = 0;
    curMax = A[1]-N+1;
    curInd = 1;
    for (int i = 2; i <= N; i++) {
        prv[i] = curInd;
        if (A[i]-(N-i) >= curMax) {
            curMax = A[i]-(N-i);
            curInd = i;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        if (prv[i] < 1 || nxt[i] > N) continue;
        ans = max(ans, A[i]+A[prv[i]]+A[nxt[i]]-(nxt[i]-prv[i]));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
