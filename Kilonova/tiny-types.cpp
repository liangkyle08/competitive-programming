#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int arr[100001];
int cost[31][31];
int pow2[31];
int low[100001];
int penalty[31];
int DP[31][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 30; i++) {
        pow2[i] = (1<<i)-1;
    }
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        for (int j = 1; j <= 30; j++) {
            if (pow2[j] >= arr[i]) {
                low[i] = j;
                break;
            }
        }
        for (int j = 1; j <= K; j++) {
            DP[j][i] = (1<<30);
        }
    }
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= K; j++) {
            cin >> cost[i][j];
        }
    }
    for (int i = 1; i <= K; i++) {
        cin >> penalty[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = low[i]; j <= K; j++) {
            for (int k = 1; k <= K; k++) {
                if (DP[k][i-1]+cost[k][j]+penalty[j-low[i]] < DP[j][i]) {
                    DP[j][i] = DP[k][i-1]+cost[k][j]+penalty[j-low[i]];
                }
            }
        }
    }
    int ans = (1<<30);
    for (int i = 1; i <= K; i++) {
        ans = min(ans, DP[i][N]);
    }
    cout << ans << "\n";
}
