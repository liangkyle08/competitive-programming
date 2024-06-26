#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[10001];
int B[10001];

int check(int ind) {
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 1; i <= ind; i++) {
        if (A[N-ind+i] != B[i]) {
            cnt1++;
        }
        if (B[N-ind+i] != A[i]) {
            cnt2++;
        }
    }
    return max(cnt1, cnt2);
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, check(i));
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
