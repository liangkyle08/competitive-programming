#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T;
string s;

void solve() {
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < (int)s.size(); i++) {
        cnt[s[i] - 'A']++;
    }
    vector<int> ind(26);
    ind['C' - 'A'] = 1;
    ind['N' - 'A'] = 1;
    ind['U' - 'A'] = 1;
    ind['A' - 'A'] = 2;
    ind['L' - 'A'] = 3;
    ind['I' - 'A'] = 4;
    ind['H' - 'A'] = 4;
    ind['O' - 'A'] = 5;
    vector<int> total(6);
    for (int i = 0; i < 26; i++) {
        if (cnt[i] && !ind[i]) {
            cout << -1 << "\n";
            return;
        }
        total[ind[i]] += cnt[i];
    }
    total[1] = (total[1] + 1) / 2;
    int ans = 0;
    for (int i = 1; i <= 5; i++) ans = max(ans, total[i]);
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
