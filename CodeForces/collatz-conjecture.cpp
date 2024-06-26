#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, K;
long long X, Y;

void solve() {
    cin >> X >> Y >> K;
    map<int, int> cnt;
    while (K > 0) {
        long long target = Y * (X / Y + 1);
        if (target - X >= K) {
            X += K;
            while (X % Y == 0) {
                X /= Y;
            }
            cout << X << "\n";
            return;
        }
        K -= (target - X);
        X = target;
        while (X % Y == 0) {
            X /= Y;
        }
        if (cnt[X] > 0) {
            long long dist = K - cnt[X];
            K %= dist;
        }
        cnt[X] = K;
    }
    cout << X << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
