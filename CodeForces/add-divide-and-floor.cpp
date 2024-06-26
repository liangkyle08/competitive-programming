#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long long arr[200001];

void solve() {
    cin >> N;
    long long minVal = (1<<30);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        minVal = min(minVal, arr[i]);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int cur = 0;
        while (arr[i] != minVal) {
            arr[i] = (arr[i] + minVal) / 2;
            cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
    if (0 < ans && ans <= N) {
        for (int i = 1; i <= ans; i++) {
            cout << minVal << " ";
        } cout << "\n";
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
