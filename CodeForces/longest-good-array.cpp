#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, L, R;

void solve() {
    cin >> L >> R;
    long long high = 1e9;
    long long low = 0;
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if ((mid * (mid - 1)) / 2 + L <= R) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
