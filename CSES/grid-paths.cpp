#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int N;
int DP[1001][1001];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            if (s[j-1] == '.') {
                if (i+j == 2) {
                    DP[1][1] = 1;
                    continue;
                }
                DP[i][j] = (DP[i-1][j]+DP[i][j-1]) % MOD;
            }
        }
    }
    cout << DP[N][N] << "\n";
}
