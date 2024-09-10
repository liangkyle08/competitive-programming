#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T;
int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int ans = 0;
        while (b--) {
            if (ans == 0) ans += 2;
            else ans -= 2;
        }
        while (a--) {
            if (ans == 0) ans++;
            else ans--;
        }
        if (ans == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
