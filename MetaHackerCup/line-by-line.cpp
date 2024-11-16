#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1000;

int T;
long double N, P;

long double solve() {
    cin >> N >> P;
    P /= 100.0;
    return 100.0 * P * (1.0 / powl(P, 1.0 / N) - 1.0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("..\\MetaHackerCup\\line-by-line-in.txt", "r", stdin);
    freopen("..\\MetaHackerCup\\line-by-line-out.txt", "w", stdout);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << fixed << setprecision(numeric_limits<double>::max_digits10) << "Case #" << i << ": " << solve() << "\n";
    }
}
