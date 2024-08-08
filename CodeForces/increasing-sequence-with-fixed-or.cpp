#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_M = 64;

int T;
long long N;
int B[MAX_M];

void solve() {
    cin >> N;
    long long t = N;
    int M = 0;
    int K = 1;
    while (t > 0) {
        B[M] = t & 1LL;
        K += B[M];
        t >>= 1LL;
        M++;
    }
    vector<long long> ans(K);
    for (int i = 0; i < K; i++) {
        int cnt = 0;
        for (int j = M - 1; j >= 0; j--) {
            if (!B[j]) {
                continue;
            }
            if (cnt < i) {
                ans[i] += (1LL << j);
            }
            else {
                if ((cnt - i) % 2 == 1) {
                    ans[i] += (1LL << j);
                }
            }
            cnt++;
        }
    }
    cout << K - !ans[0] << "\n";
    for (auto v: ans) {
        if (v == 0) continue;
        cout << v << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
