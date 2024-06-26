#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
long long N;

long long check(long long k, long long n) {
    long long A = 1;
    for (int i = 0; i < n; i++) {
        A *= k;
        if (A > (1LL << 60)) {
            return (1LL << 60);
        }
    }
    return (A-1)/(k-1);
}

void solve() {
    cin >> N;
    for (int i = 3; i <= 63; i++) { // Repeated times
        for (int j = 2; j <= 1000; j++) {
            if (check((long long)j, (long long)i) == N) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
