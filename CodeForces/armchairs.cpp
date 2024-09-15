#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 5000;

int N;
int A[MAX_N + 5];
int ind[MAX_N + 5];
int DP[MAX_N + 5][MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int K = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (!A[i]) continue;
        K++;
        ind[K] = i;
    }
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j <= K + 1; j++) {
            DP[i][j] = INF;
        }
    }
    DP[1][1] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K + 1; j++) {
            if (DP[i][j] == INF) continue;
            DP[i + 1][j] = min(DP[i + 1][j], DP[i][j]);
            if (j > K || A[i] == 1) continue;
            DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j] + abs(ind[j] - i));
        }
    }
    cout << DP[N + 1][K + 1] << "\n";
}