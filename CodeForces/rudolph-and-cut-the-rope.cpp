#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

void solve() {
    cin >> N;
    vector<pair<int, int>> arr(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    sort(arr.begin(), arr.end());
    arr[0].fi = -1;
    int ans = N;
    for (int h = 0; h <= 500; h++) {
        bool flag = true;
        for (int j = 1; j <= N; j++) {
            if (abs(arr[j].fi-h) > arr[j].se) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int cnt = 0;
            for (int j = 1; j <= N; j++) {
                if (arr[j].fi-arr[j].se > 0) {
                    cnt++;
                }
            }
            cout << cnt << '\n';
            return;
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
