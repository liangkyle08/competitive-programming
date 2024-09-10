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
pair<int, int> A[MAX_N + 5];

void solve() {
    cin >> N;
    map<int, long long> xFreq, yFreq;
    map<pair<int, int>, bool> seen;
    for (int i = 1; i <= N; i++) {
        cin >> A[i].fi >> A[i].se;
        seen[A[i]] = true;
        xFreq[A[i].fi]++;
        yFreq[A[i].se]++;
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += (xFreq[A[i].fi] - 1) * (yFreq[A[i].se] - 1);
        if (A[i].se == 0) {
            ans += seen[{A[i].fi + 1, 1}] && seen[{A[i].fi + 2, 0}];
        }
        else {
            ans += seen[{A[i].fi + 1, 0}] && seen[{A[i].fi + 2, 1}];
        }
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
