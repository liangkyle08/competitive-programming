#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int H, W;
int DP[1001][1001];

int main() {
    cin >> H >> W;
    DP[1][1] = 1;
    for (int i = 1; i <= H; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= W; j++) {
            if (s[j-1] == '.' && i+j != 2) {
                DP[i][j] = (DP[i-1][j]+DP[i][j-1]) % MOD;
            }
        }
    }
    cout << DP[H][W] << "\n";
}
