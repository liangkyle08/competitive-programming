#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, X;
int arr[51];

void solve() {
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int ans = max(arr[1], 2*(X-arr[N]));
    for (int i = 1; i < N; i++) {
        ans = max(ans, arr[i+1]-arr[i]);
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
