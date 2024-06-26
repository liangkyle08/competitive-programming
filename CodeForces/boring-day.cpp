#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, L, R;
int A[200005];

void solve() {
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    int cur = 0;
    int p1 = 1;
    for (int p2 = 1; p2 <= N; p2++) {
        cur += A[p2];
        while (cur > R && p1 <= p2) {
            cur -= A[p1];
            p1++;
        }
        if (L <= cur && cur <= R) {
            ans++;
            p1 = p2+1;
            cur = 0;
            continue;
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
