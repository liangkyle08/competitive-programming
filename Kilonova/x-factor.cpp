#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
long long arr[1505][1505];
long long diag1[1505][1505];
long long diag2[1505][1505];
long long diag3[1505][1505];
long long diag4[1505][1505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("xfactor.in", "r", stdin);
    freopen("xfactor.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            diag1[i][j] = max(arr[i][j], diag1[i-1][j-1]+arr[i][j]);
            diag2[i][j] = max(arr[i][j], diag2[i-1][j+1]+arr[i][j]);
        }
    }
    for (int i = N; i >= 1; i--) {
        for (int j = M; j >= 1; j--) {
            diag3[i][j] = max(arr[i][j], diag3[i+1][j-1]+arr[i][j]);
            diag4[i][j] = max(arr[i][j], diag4[i+1][j+1]+arr[i][j]);
        }
    }
    long long ans = -(1LL<<60);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans = max(ans, diag1[i][j]+diag2[i][j]+diag3[i][j]+diag4[i][j]-3*arr[i][j]);
        }
    }
    cout << ans << "\n";
}
