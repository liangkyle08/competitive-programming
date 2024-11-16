#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int T, N;
int A[MAX_N + 5];
bool sieve[MAX_N + 5];
set<int> primes;
bool seen[MAX_N + 5];

void solve() {
    cin >> N;
    memset(seen, false, sizeof(seen));
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    map<int, bool> largePrimes;
    bool ans = false;
    for (int i = 1; i <= N; i++) {
        for (auto &j : primes) {
            if (A[i] < j * j || A[i] < 1) break;
            if (A[i] % j != 0) continue;
            if (seen[j]) {
                ans = true;
                break;
            }
            seen[j] = true;
            while (A[i] % j == 0) {
                A[i] /= j;
            }
        }
        if (A[i] > 1) {
            if (A[i] <= MAX_N) {
                if (seen[A[i]]) {
                    ans = true;
                    break;
                }
                seen[A[i]] = true;
            }
            else {
                if (largePrimes[A[i]]) {
                    ans = true;
                    break;
                }
                largePrimes[A[i]] = true;
            }
        }
        if (ans) break;
    }
    cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 4; i <= MAX_N; i += 2) sieve[i] = false;
    for (int i = 3; i * i <= MAX_N; i += 2) {
        if (!sieve[i]) continue;
        for (int j = i * i; j <= MAX_N; j += 2 * i) {
            sieve[j] = false;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (!sieve[i]) continue;
        primes.insert(i);
    }
    cin >> T;
    while (T--) {
        solve();
    }
}