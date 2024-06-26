#include <bits/stdc++.h>
using namespace std;

int N;
int DP[100001][4];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int cur[4];
        cin >> cur[1] >> cur[2] >> cur[3];
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (k == j) continue;
                if (DP[i][j]+cur[k] > DP[i+1][k]) {
                    DP[i+1][k] = DP[i][j]+cur[k];
                }
            }
        }
    }
    cout << max(DP[N][1], max(DP[N][2], DP[N][3])) << "\n";
}
