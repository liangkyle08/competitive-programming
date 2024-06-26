#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
long long arr[2001][2001];
long long pSum[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i+j-1][N-i+j];
        }
    }
    for (int i = 1; i <= 2*N; i++) {
        for (int j = 1; j <= 2*M; j++) {
            pSum[i][j] = pSum[i-1][j]+pSum[i][j-1]-pSum[i-1][j-1]+arr[i][j];
        }
    }
    long long maxSum = 0LL;
    pair<int, int> ans;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int minDist = min(min(i, j), min(N-i+1, M-j+1))-1;
            int A = (i+j-1)+minDist;
            int B = (N-i+j)+minDist;
            int a = (i+j-1)-minDist;
            int b = (N-i+j)-minDist;
            long long curSum = pSum[A][B]-pSum[a-1][B]-pSum[A][b-1]+pSum[a-1][b-1];
            if (curSum > maxSum) {
                maxSum = curSum;
                ans = {i, j};
            }
        }
    }
    cout << ans.fi << " " << ans.se << "\n";
}
