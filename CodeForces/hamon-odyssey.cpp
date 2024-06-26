#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[200001];

void solve() {
    cin >> N;
    vector<int> cnt(31);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        for (int j = 0; j < 31; j++) {
            if (arr[i] & (1 << j)) continue;
            cnt[j]++;
        }
    }
    int ans = N;
    int sum = 0;
    bool flag = true;
    for (int i = 0; i < 31; i++) {
        ans = min(ans, max(1, cnt[i]));
        sum += N-cnt[i];
        if (N-cnt[i] > 1) {
            flag = false;
        }
    }
    if (flag && sum > 0) ans = 1;
    cout << ans << '\n';
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
