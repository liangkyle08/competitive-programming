#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        if (N-((N+M-1) / M) <= K) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}
