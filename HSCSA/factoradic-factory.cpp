#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
long long N;
long long fact[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    fact[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fact[i] = fact[i-1]*i;
        //cout << fact[i] << "\n";
    }
    cin >> T;
    while (T--) {
        cin >> N;
        vector<long long> ans(21);
        for (int i = 20; i >= 1; i--) {
            ans[i] = N / fact[i];
            N %= fact[i];
        }
        int stop = 0;
        for (int i = 20; i >= 1; i--) {
            if (ans[i] > 0) {
                stop = i;
                break;
            }
        }
        for (int i = stop; i >= 1; i--) {
            cout << ans[i];
            if (i > 1) cout << ":";
        }
        if (stop == 0) {
            cout << 0;
        } cout << "\n";
    }
}
