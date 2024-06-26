#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

void solve() {
    cin >> N;
    int i = 0;
    int curNum = 0;
    while (i <= 30) {
        curNum += (1<<i);
        if (curNum > N) break;
        i++;
    }
    if ((1<<i) <= N) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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
