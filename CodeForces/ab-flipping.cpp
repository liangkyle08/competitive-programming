#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

void solve() {
    cin >> N;
    string s;
    cin >> s;
    int startInd = 0;
    int endInd = (int)s.size()-1;
    while (s[startInd] != 'A' && startInd < (int)s.size()-1) startInd++;
    while (s[endInd] != 'B' && endInd > 0) endInd--;
    cout << max(0, endInd-startInd) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
