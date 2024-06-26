#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int C[200001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }
    long long ans = 0;
    for (int i = 1; i < N; i++) {
        if (C[i] > C[i+1]) {
            ans += (C[i]-C[i+1]);
        }
    }
    ans += C[N];
    if (C[1] > 0) {
        ans--;
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
