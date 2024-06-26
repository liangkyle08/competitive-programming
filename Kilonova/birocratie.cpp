#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int B[1001][1001];
int DP[1001][1001];
int DP2[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("birocratie.in", "r", stdin);
    freopen("birocratie.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> B[i][j];
            DP[i][j] = -(1<<30);
            DP2[i][j] = -(1<<30);
        }
    }
    for (int x = 1; x <= 2*N; x++) {
        int i = x+1;
        int j = 0;
        vector<int> sumArray, maxArray;
        map<pair<int, int>, int> sums;
        int sum = 0;
        while (--i >= 1 && ++j <= N) {
            if (i > N) continue;
            sum += B[i][j];
            sums[{i, j}] = sum+DP[i][j];
            sumArray.push_back(sum+DP[i][j]);
            maxArray.push_back(sumArray.back());
        }
        int k = maxArray.size();
        while (--k >= 0) {
            if (k == maxArray.size()-1) continue;
            maxArray[k] = max(maxArray[k], maxArray[k+1]);
        }
        i = x+1; j = 0; sum = 0; k = 0;
        while (--i >= 1 && ++j <= N) {
            if (i > N) continue;
            sum += B[i][j];
            DP2[i][j] = max(DP2[i][j], maxArray[k]-sum+B[i][j]);
            k++;
        }
        sums.clear();
        sumArray.clear();
        maxArray.clear();
        i = 0; j = x+1; sum = 0;
        while (++i <= N && --j >= 1) {
            if (j > N) continue;
            sum += B[i][j];
            sumArray.push_back(sum+DP[i][j]);
            maxArray.push_back(sumArray.back());
        }
        k = maxArray.size();
        while (--k >= 0) {
            if (k == maxArray.size()-1) continue;
            maxArray[k] = max(maxArray[k], maxArray[k+1]);
        }
        i = 0; j = x+1; sum = 0; k = 0;
        while (++i <= N && --j >= 1) {
            if (j > N) continue;
            sum += B[i][j];
            DP2[i][j] = max(DP2[i][j], maxArray[k]-sum+B[i][j]);
            k++;
        }
        if (x == 1) {
            DP2[1][1] = B[1][1];
        }
        i = x+1; j = 0;
        while (--i >= 1 && ++j <= N) {
            if (i > N) continue;
            DP[i][j] = DP2[i][j];
            if (i+1 <= N) {
                DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
            }
            if (j+1 <= N) {
                DP[i][j+1] = max(DP[i][j+1], DP[i][j]);
            }
        }
    }
    cout << DP[N][N] << "\n";
}
