#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int B[1001];
int mod = 0;

bool cmp(int u, int v) {
    return (u % mod) > (v % mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    int ans = 0;
    for (int val = 1; val <= 1000; val++) {
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += B[i]/val;
        }
        if (cnt < K/2) continue;
        if (cnt > K) {
            ans = max(ans, val*(K/2));
            continue;
        }
        mod = val;
        sort(B+1, B+N+1, cmp);
        int cur = val*(cnt-K/2);
        for (int i = 1; i <= N; i++) {
            if (cnt == K) break;
            cur += B[i] % val;
            cnt++;
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
