#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long arr[201];
long long DP[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        DP[i][1] = arr[i];
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= i; j++) {
            for (int k = 2; k <= j; k++) {
                DP[i][j] = max(DP[i][j], (DP[i][k-1]+DP[i-k+1][j-k+1])/2);
            }
        }
    }
    /*for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << DP[i][j] << ' ';
        } cout << '\n';
    }*/
    cout << DP[N][N] << "\n";
}
