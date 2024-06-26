#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 998244353;

int N;
int arr[200001][3];
int DP[200001][3];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][1] >> arr[i][2];
    }
    DP[1][1] = 1;
    DP[1][2] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= 2; j++) {
            if (arr[i-1][j] != arr[i][j]) {
                DP[i][j] = (DP[i][j]+DP[i-1][j]) % MOD;
            }
            if (arr[i-1][3-j] != arr[i][j]) {
                DP[i][j] = (DP[i][j]+DP[i-1][3-j]) % MOD;
            }
        }
    }
    cout << (DP[N][1]+DP[N][2]) % MOD << "\n";
}
