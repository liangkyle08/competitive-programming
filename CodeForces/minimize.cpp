#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int ans = INF;
        for (int c = a; c <= b; c++) {
            ans = min(ans, (c - a) + (b - c));
        }
        cout << ans << "\n";
    }
}
