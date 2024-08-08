#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

int T, N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        int ans = 0;
        while (N > 1) {
            N -= (K - 1);
            ans++;
        }
        cout << ans << "\n";
    }
}
