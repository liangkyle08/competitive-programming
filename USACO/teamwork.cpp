#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int arr[10001];
int DP[10001];

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        // Case #1
        DP[i] = max(DP[i], arr[i]+DP[i-1]);
        // Case #2
        int mx = arr[i];
        for (int j = 2; j <= K; j++) {
            if (i-j < 0) break;
            mx = max(mx, arr[i-j+1]);
            DP[i] = max(DP[i], j*mx+DP[i-j]);
        }
    }
    cout << DP[N] << "\n";
}
