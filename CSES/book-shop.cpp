#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, X;
int DP[100001];

int main() {
    cin >> N >> X;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].fi;
    }
    for (int i = 0; i < N; i++) {
        cin >> arr[i].se;
    }
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (auto [w, v]: arr) {
        for (int i = X-w; i >= 0; i--) {
            if (DP[i] < 0) continue;
            if (DP[i]+v >= DP[i+w]) {
                DP[i+w] = DP[i]+v;
                ans = max(ans, DP[i+w]);
            }
        }
    }
    cout << ans << '\n';
}
