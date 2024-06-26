#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
int arr[1001];

bool check(int val, int ind) {
    int k = K;
    for (int i = ind; i <= N; i++) {
        if (val <= arr[i]) {
            return true;
        }
        if (val-arr[i] <= k) {
            k -= (val-arr[i]);
            val--;
        }
        else {
            return false;
        }
    }
    return false;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int high = arr[i]+K+1;
        int low = arr[i];
        while (low < high) {
            int mid = (high+low+1)/2;
            if (check(mid, i)) {
                low = mid;
            }
            else {
                high = mid-1;
            }
        }
        ans = max(ans, low);
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
