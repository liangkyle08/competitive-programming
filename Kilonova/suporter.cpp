#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M, K;
int DP[301][301][6]; // team, stage, # of changes
pair<int, int> maxInd[301][6];
int score[301][301];
multiset<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> score[i][j];
            if (j == 1) {
                DP[i][j][0] = score[i][j];
                s.insert(DP[i][j][0]);
            }
        }
    }
    maxInd[1][0].fi = *s.end();
    s.erase(s.end());
    if (!s.empty()) {
        maxInd[1][0].se = *s.end();
    }
    s.clear();
    for (int pos = 2; pos <= M; pos++) {
        for (int i = 1; i <= N; i++) {
            for (int p = 0; p <= K; p++) {
                // Change teams
                int val = maxInd[pos-1][p].fi;
                if (val == score[i][pos]) {
                    val = maxInd[pos-1][p].se;
                }
                if (p+1 <= K) {
                    DP[i][pos][p+1] = max(DP[i][pos][p+1], val+score[i][pos]);
                }
                // Don't change
                DP[i][pos][p] = max(DP[i][pos][p], DP[i][pos-1][p]+score[i][pos]);
            }
            for (int p = 0; p <= K; p++) {
                s.insert(DP[i][pos]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            ans = max(ans, DP[i][M][j]);
        }
    }
    cout << ans << '\n';
}
