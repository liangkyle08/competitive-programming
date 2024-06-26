#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;

int match(int x, int y, int a, int b) {
    int total = 0;
    int cnt = 0;
    while (x != a) {
        while (x < a) { // Lower Numerator "a"
            if (a == b) break;
            if (a < b) { // Lower Denominator "b" first
                cnt = (b-a+(a-1))/a;
                b -= a*cnt;
                total += cnt;
            }
            else {
                cnt = (a-b+(b-1))/b;
                a -= b*cnt;
                total += cnt;
            }
        }
        if (x == a) break;
        while (a < x) {
            if (x == y) break;
            if (x < y) {
                cnt = (y-x+(x-1))/x;
                y -= x*cnt;
                total += cnt;
            }
            else {
                cnt = (x-y+(y-1))/y;
                x -= y*cnt;
                total += cnt;
            }
        }
    }
    if (y < b) swap(y, b);
    total += (y-b)/x;
    return total;
}

void solve() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    // Match the Numerators
    int ans = match(x, y, a, b);
    swap(x, y);
    swap(a, b);
    // Match the Denominators
    ans = min(ans, match(x, y, a, b));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("numinum.in", "r", stdin);
    //freopen("numinum.out", "w", stdout);
    cin >> N;
    while (N--) {
        solve();
    }
}
