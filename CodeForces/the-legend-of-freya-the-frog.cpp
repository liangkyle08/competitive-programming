#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T;
long long X, Y, K;

void solve() {
    cin >> X >> Y >> K;
    long long xJumps = (X + K - 1) / K;
    long long yJumps = (Y + K - 1) / K;
    if (yJumps < xJumps - 1) {
        yJumps = xJumps - 1;
        cout << xJumps + yJumps << "\n";
        return;
    }
    if (yJumps > xJumps) {
        xJumps = yJumps;
        cout << xJumps + yJumps << "\n";
        return;
    }
    cout << xJumps + yJumps << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
