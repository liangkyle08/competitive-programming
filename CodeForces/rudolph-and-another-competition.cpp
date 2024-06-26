#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M, H;

void solve() {
    cin >> N >> M >> H;
    vector<pair<pair<int, long long>, int>> final;
    for (int i = 1; i <= N; i++) {
        vector<int> arr(M);
        for (auto &v: arr) cin >> v;
        int points = 0;
        long long penalty = 0;
        int curTime = 0;
        sort(arr.begin(), arr.end());
        for (auto v: arr) {
            if (curTime+v <= H) {
                points++;
                curTime += v;
                penalty += (curTime);
            }
            else {
                break;
            }
        }
        final.push_back({{-points, penalty}, i});
    }
    sort(final.begin(), final.end());
    for (int i = 1; i <= N; i++) {
        if (final[i-1].se == 1) {
            cout << i << "\n";
            break;
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
