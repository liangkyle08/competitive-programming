#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
bool arr[300001];
string s;

void solve() {
    cin >> N >> s;
    for (int i = 1; i <= N; i++) {
        arr[i] = (s[i-1] == '1');
    }
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= N; i++) {
        cur++;
        if (i == N || arr[i] == arr[i+1]) {
            ans += cur/3;
            cur = 0;
            continue;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
