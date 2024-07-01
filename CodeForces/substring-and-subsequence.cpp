#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
string A, B;

void solve() {
    cin >> A >> B;
    int ans = (int)A.size()+(int)B.size();
    for (int i = 0; i < (int)B.size(); i++) {
        int cur = B.size();
        int diff = 0;
        for (int j = 0; j < (int)A.size(); j++) {
            if (i+diff >= (int)B.size()) {
                cur += (int)A.size()-j;
                break;
            }
            if (B[i+diff] != A[j]) {
                cur++;
                continue;
            }
            diff++;
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
