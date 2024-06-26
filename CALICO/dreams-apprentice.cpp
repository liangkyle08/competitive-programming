#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> s >> t;
        int mxAir = 0;
        int curAir = 0;
        for (int i = 1; i <= N; i++) {
            if (s[i-1] == t[i-1]) {
                curAir++;
                mxAir = max(mxAir, curAir);
            }
            else {
                curAir = 0;
            }
        }
        cout << ((mxAir <= 4) ? "YES" : "banned") << "\n";
    }
}
