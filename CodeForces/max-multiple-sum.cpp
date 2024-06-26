#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        int ans = 0;
        int maxSum = 0;
        for (int x = 2; x <= N; x++) {
            int curSum = 0;
            for (int k = 1; x*k <= N; k++) {
                curSum += x*k;
            }
            if (curSum > maxSum) {
                maxSum = curSum;
                ans = x;
            }
        }
        cout << ans << "\n";
    }
}
