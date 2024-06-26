#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K, D;
int arr[101];
long long DP[101][101][101]; // First "i" items, choose "j" items, mod is equal to k
bool seen[101][101][101];

int main() {
    cin >> N >> K >> D;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    long long ans = -1;
    seen[0][0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k < D; k++) {
                int x = (DP[i-1][j-1][k]+arr[i]) % D;
                if (seen[i-1][j-1][k]) {
                    DP[i][j][x] = max(DP[i][j][x], DP[i-1][j-1][k]+arr[i]); // Add this item
                    DP[i][j-1][k] = max(DP[i][j-1][k], DP[i-1][j-1][k]); // Didn't add this item
                    seen[i][j][x] = true;
                    seen[i][j-1][k] = true;
                }
                if (x == 0 && j == K && seen[i][j][x]) {
                    ans = max(ans, DP[i][j][x]);
                }
            }
        }
    }
    cout << ans << "\n";
}
