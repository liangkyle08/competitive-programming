#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, Q;
long long arr[100001];
int K[100001];
int total[100001];
int pSum[100001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        long long cur = 1;
        for (int j = 1; j <= 20; j++) {
            cur *= (long long)j;
            if (arr[i] % cur > 0) {
                break;
            }
            K[i] = j;
        }
        // cout << K[i] << "\n";
    }
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = i; j <= min(j+19, N); j++) {
            if (cnt+1 > K[j]) break;
            total[j]++;
            cout << j << " " << total[j] << "\n";
            cnt++;
        }
        pSum[i] = pSum[i-1]+total[i];
        //cout << total[i] << "\n";
    }
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << pSum[R]-pSum[L-1]-L*pSum[L-1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> T;
    while (T--) {
        solve();
    }
}
