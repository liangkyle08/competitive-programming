// Codeforces Round 881 (Div. 3)
// C. Sum in Binary Tree
// https://codeforces.com/contest/1843/problem/C

#include <bits/stdc++.h>
using namespace std;

int T;
long long N;

void solve() {
    cin >> N;
    long long ans = N;
    while (N != 1) {
        N /= 2;
        ans += N;
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
