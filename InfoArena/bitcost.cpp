#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int K, M;
long long A, B;
long long cost[61];
long long mx[61];

long long solve(long long L, long long R, int pos, long long add) {
    if (A <= L && L+(1LL<<pos)-1 <= B) {
        return mx[pos]+add;
    }
    if (R < A || L > B) {
        return -(1LL<<30);
    }
    if (pos == 0) {
        return add;
    }
    return max(solve(L, R-(1LL<<(pos-1)), pos-1, add), solve(L+(1LL<<(pos-1)), R, pos-1, add+cost[pos]));
}

int main() {
    freopen("bitcost.in", "r", stdin);
    freopen("bitcost.out", "w", stdout);
    cin >> K >> M;
    for (int i = 1; i <= K; i++) {
        cin >> cost[i];
        mx[i] = mx[i-1]+max(0LL, cost[i]);
    }
    while (M--) {
        cin >> A >> B;
        cout << solve(0, (1LL<<K)-1, K, 0LL) << "\n";
    }
}