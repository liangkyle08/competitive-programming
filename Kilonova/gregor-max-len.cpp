#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

void solve() {
    cin >> N;
    vector<int> A(N+1);
    map<int, int> leftInd, rightInd, cnt;
    set<int> vals;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (leftInd[A[i]] == 0) {
            leftInd[A[i]] = i;
        }
        rightInd[A[i]] = i;
        cnt[A[i]]++;
        vals.insert(A[i]);
    }
    vector<int> DP(N+1);
    for (int i = 1; i <= N; i++) {
        DP[i] = DP[i-1];
        if (i == rightInd[A[i]]) {
            for (auto v: vals) {
                if (v >= A[i] || rightInd[v] > leftInd[A[i]]) continue;
                DP[i] = max(DP[i], DP[rightInd[v]]+cnt[A[i]]);
            }
            DP[i] = max(DP[i], cnt[A[i]]);
        }
    }
    cout << max(DP[N], 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
