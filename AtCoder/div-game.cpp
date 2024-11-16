#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

long long N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    long long ans = 0;
    for (long long i = 2; i * i <= N; i++) {
        long long j = i;
        while (N % j == 0) {
            N /= j;
            j *= i;
            ans++;
        }
        while (N % i == 0) {
            N /= i;
        }
    }
    if (N > 1) {
        ans++;
    }
    cout << ans << "\n";
}
