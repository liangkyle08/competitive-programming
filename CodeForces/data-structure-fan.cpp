#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, Q;
int A[100001];
int pref[100001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        pref[i] = A[i] ^ pref[i-1];
    }
    string s;
    cin >> s;
    vector<int> val(2);
    for (int i = 1; i <= N; i++) {
        val[s[i-1]-'0'] ^= A[i];
    }
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int L, R;
            cin >> L >> R;
            val[0] ^= (pref[R]^pref[L-1]);
            val[1] ^= (pref[R]^pref[L-1]);
        }
        else {
            int g;
            cin >> g;
            cout << val[g] << " ";
        }
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
