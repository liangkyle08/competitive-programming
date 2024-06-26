#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long X;
string s;
long long pow2[61];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    pow2[0] = 1LL;
    for (int i = 1; i <= 60; i++) {
        pow2[i] = pow2[i-1]*2LL;
    }
    cin >> s >> X;
    N = (int)s.size();
    int depth = 0;
    for (int i = 0; i <= 60; i++) {
        if (N*pow2[i] >= X) {
            depth = i;
            break;
        }
    }
    while (depth > 0) {
        long long len = N*pow2[depth-1];
        if (X > len) {
            X = (X-len-1);
            if (X == 0) X = len;
        }
        depth--;
    }
    cout << s[X-1] << "\n";
}
