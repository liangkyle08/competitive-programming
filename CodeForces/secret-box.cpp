#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
long long X, Y, Z, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> X >> Y >> Z >> K;
        vector<array<long long, 3>> pos;
        for (long long i = 1; i <= X; i++) {
            for (long long j = 1; j <= Y; j++) {
                if (i * j > K) continue;
                if (K % (i * j) != 0) continue;
                if (K / (i * j) > Z) continue;
                pos.push_back({i, j, K / (i * j)});
            }
        }
        long long ans = 0LL;
        for (auto [a, b, c]: pos) {
            long long cur = (X-a+1)*(Y-b+1)*(Z-c+1);
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}
