#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
int DP[32][200001]; // At least 30 (not 20) in this problem

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int u = 1; u <= N; u++) {
        cin >> DP[0][u];
    }
    for (int i = 1; i <= 30; i++) { // Notice this is the outer for-loop
        for (int u = 1; u <= N; u++) {
            DP[i][u] = DP[i-1][DP[i-1][u]];
        }
    }
    while (Q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 30; i >= 0; i--) {
            if ((1<<i) <= k) {
                x = DP[i][x];
                k -= (1<<i);
            }
        }
        cout << x << "\n";
    }
}
