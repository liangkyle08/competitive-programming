#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
long long W, D, L, goalsA, goalsB;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> W >> D >> L >> goalsA >> goalsB;
        if (W > goalsA || L > goalsB) {
            cout << "Better luck next time\n";
            continue;
        }
        cout << (goalsA-W > 1) << (goalsB-L > 1) << "\n";
        if ((goalsA-W > 1) || (goalsB-L > 1)) {
            cout << "Better luck next time\n";
            continue;
        }
        if ((W > 0 && D > 0)
            || (W > 0 && L > 0)
            || (D > 0 && L > 0)) {
            cout << "Better luck next time\n";
            continue;
        }
        cout << "Amazing\n";
    }
}
