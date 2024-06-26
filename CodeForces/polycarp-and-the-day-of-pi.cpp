#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
string s;
string pi = "314159265358979323846264338327";

void solve() {
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == pi[i]) {
            ans++;
        }
        else {
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
