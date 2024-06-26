#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int MAX_N = 65000000;

int A, B;
bool seen[MAX_N];
set<int> primes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i <= MAX_N; i++) {
        if (seen[i]) continue;
        primes.insert(i);
        for (int j = i; j <= MAX_N; j += i) {
            seen[j] = true;
        }
    }
    cout << (int)primes.size() << "\n";
    cin >> A >> B;
}
