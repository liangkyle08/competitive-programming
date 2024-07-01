#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
string s;

void solve() {
    cin >> N >> s;
    int ans = (1<<30);
    for (int i = 0; i < N-1; i++) {
        vector<int> vals;
        for (int j = 0; j < N; j++) {
            if (j == i+1) continue;
            if (j == i) {
                vals.push_back((s[j] - '0') * 10 + (s[j+1] - '0'));
                continue;
            }
            vals.push_back(s[j] - '0');
        }
        int cur = 0;
        while (!vals.empty()) {
            int v = vals.back();
            vals.pop_back();
            if (v == 0) {
                cur = 0;
                break;
            }
            if (v == 1) {
                if (vals.empty() && cur == 0) cur++;
                continue;
            }
            cur += v;
        }
        ans = min(ans, cur);
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
