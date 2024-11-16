#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T;
long long N, B, C;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> B >> C;
        if (B == 0) {
            if (C >= N - 2) {
                cout << N - (C <= N - 1) << "\n";
                continue;
            }
            cout << -1 << "\n";
            continue;
        }
        long long cnt = ((N - 1) - C) / B + 1;
        cout << (C > N - 1 ? N : N - cnt) << "\n";
    }
}
