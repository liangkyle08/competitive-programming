#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
int arr[2001];
long long DP[2001][2001]; // First "i" items, choose "j" items

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            DP[i][j] = -(1LL<<60);
        }
    }
    DP[0][0] = 0;
    long long ans = -(1LL<<60);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            DP[i][j] = max(DP[i][j], DP[i-1][j-1]+(j*arr[i]));
            DP[i][j-1] = max(DP[i][j-1], DP[i-1][j-1]);
            if (j == M) {
                ans = max(ans, DP[i][j]);
            }
        }
    }
    cout << ans << "\n";
}
