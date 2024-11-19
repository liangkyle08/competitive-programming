#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T;
double N, H, D, S, P;

void solve() {
    cin >> N >> H >> D >> S >> P;
    double t1 = D / S; // time to run without stops
    double remainingHealth = N - P * t1;
    if (remainingHealth >= 0.0) {
        cout << t1 << "\n";
        return;
    }
    if (H <= P) {
        cout << -1.0 << "\n";
        return;
    }
    double t2 = -remainingHealth / (H - P); // time to heal
    cout << t1 + t2 << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
