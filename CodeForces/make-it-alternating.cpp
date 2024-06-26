#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 998244353;

int T, N;
string s;
bool arr[200001];

long long factorial(long long x) {
    long long total = 1LL;
    for (long long i = 1; i <= x; i++) {
        total = (total*i) % MOD;
    }
    return total;
}

void solve() {
    cin >> s;
    N = (int)s.size();
    for (int i = 1; i <= N; i++) {
        arr[i] = (s[i-1] == '1');
    }
    int curVal = arr[1];
    int curLen = 1;
    int minOper = 0;
    long long ans = 1LL;
    for (int i = 2; i <= N; i++) {
        if (arr[i] == curVal) {
            minOper++;
            curLen++;
            continue;
        }
        curVal = arr[i];
        ans = (ans*curLen) % MOD;
        curLen = 1;
    }
    ans = (ans*curLen) % MOD;
    ans = (ans*factorial(minOper)) % MOD;
    cout << minOper << " " << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
