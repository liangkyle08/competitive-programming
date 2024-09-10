#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, N;

void solve() {
    cin >> N;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= 4; j++) {
            if (s[j - 1] != '#') continue;
            ans.push_back(j);
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto &v: ans) {
        cout << v << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
