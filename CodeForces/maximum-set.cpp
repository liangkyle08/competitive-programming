// Educational Codeforces Round 144 (Rated for Div. 2)
// C. Maximum Set
// https://codeforces.com/problemset/problem/1796/C

#include <bits/stdc++.h>
using namespace std;

int T, l, r;

void solve() {
    cin >> l >> r;
    int maxSize = 1;
    while (l*(int)pow(2, maxSize) <= r) {
        maxSize++;
    }
    int ans = (r / (int)pow(2, maxSize - 1) - l + 1);
    if (maxSize > 1) {
        ans += (maxSize - 1) * max(0, (r / (int)pow(2, maxSize-2)) / 3 - l + 1);
    }
    cout << maxSize << " " << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
