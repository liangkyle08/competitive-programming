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
    int i = 0;
    while (i < (int)s.size()) {
        if (s[i] == 'O') {
            cout << "[###OREO###]\n";
            i++;
            continue;
        }
        if (s[i] == 'R') {
            cout << " [--------] \n";
            i += 2;
            continue;
        }
        cout << "\n";
        i++;
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
