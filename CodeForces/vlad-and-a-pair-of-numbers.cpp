#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, X;

void solve() {
    cin >> X;
    bool pos = true;
    if (X % 2 == 1) {
        pos = false;
    }
    int A = X/2;
    int B = X+X/2;
    if ((A^B) != X || A+B != 2*X) {
        pos = false;
    }
    if (pos) {
        cout << A << " " << B << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
