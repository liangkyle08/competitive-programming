#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int PRIMES[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int T, N;
long long A[101];

void solve() {
    cin >> N;
    map<long long, int> freq;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }
    for (auto [u, v]: freq) {
        if (v >= 2) {
            cout << "NO\n";
            return;
        }
    }
    for (auto p: PRIMES) {
        map<long long, int> rem;
        int cnt = p;
        for (int i = 1; i <= N; i++) {
            rem[A[i] % p]++;
            if (rem[A[i] % p] == 2) cnt--;
        }
        if (cnt == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
