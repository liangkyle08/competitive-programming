#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
string s;

void solve() {
    cin >> N >> s;
    int ans = 0;
    int maxLen = 0;
    int curLen = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            maxLen = max(maxLen, curLen);
            ans += min(curLen, 2);
            curLen = 0;
        }
        else {
            curLen++;
        }
    }
    maxLen = max(maxLen, curLen);
    ans += min(curLen, 2);
    if (maxLen > 2) {
        ans = 2;
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
