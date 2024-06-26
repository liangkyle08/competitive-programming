#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M, A, B;

void solve() {
    cin >> N >> M >> A >> B;
    multiset<int> s;
    for (int i = 1; i <= M; i++) {
        int v;
        cin >> v;
        s.insert(-v);
    }
    if (B < A) { // "Flip" everything so everyone moves to the right
        B = N-B+1;
        A = N-A+1;
    }
    int ans = 0;
    for (int i = 1; i <= min(B-A-1, M); i++) {
        auto it = s.upper_bound(i-B);
        if (it == s.end()) continue;
        s.erase(it);
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
