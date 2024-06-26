#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
long long N, X, K;

long long numNodes(long long val, long long dist) {
    cout << val << " " << dist << "\n";
    if (val > N) return 0;
    if (dist == 0) return 1;
    return numNodes(2*val, dist-1)+numNodes(2*val+1, dist-1);
}

void solve() {
    cin >> N >> X >> K;
    long long ans = numNodes(X, K);
    int distToRoot = 0;
    int otherHalf = 0;
    /*while (X != 1) {
        distToRoot++;
        if (X == 2) {
            otherHalf = 3;
        }
        if (X == 3) {
            otherHalf = 2;
        }
        X /= 2;
    }
    if (distToRoot >= K && K != 0) {
        ans++;
    }
    if (distToRoot < K && K != 0) {
        ans += numNodes(otherHalf, K-distToRoot-1);
    }
    cout << ans << "\n";*/
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
