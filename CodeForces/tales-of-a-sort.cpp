#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[52];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    bool flag = false;
    int ans = 0;
    for (int i = N-1; i >= 1; i--) {
        if (arr[i] > arr[i+1]) flag = true;
        if (flag) {
            ans = max(ans, arr[i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
