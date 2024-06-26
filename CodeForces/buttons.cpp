#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
long long A, B, C;

void solve() {
    cin >> A >> B >> C;
    A += C/2 + (C % 2 == 1);
    B += C/2;
    if (A > B) {
        cout << "First\n";
    }
    else {
        cout << "Second\n";
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
