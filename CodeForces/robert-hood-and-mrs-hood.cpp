#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int T, N, D, K;


void solve() {
    cin >> N >> D >> K;
    vector<int> pSum(N + 5);
    for (int i = 1; i <= K; i++) {
        int L, R;
        cin >> L >> R;
        pSum[max(L - D + 1, 1)]++;
        pSum[R + 1]--;
    }
    for (int i = 1; i <= N; i++) {
        pSum[i] += pSum[i - 1];
    }
    int maxVal = -INF;
    int maxInd = 0;
    int minVal = INF;
    int minInd = 0;
    for (int i = 1; i <= N - D + 1; i++) {
        if (pSum[i] > maxVal) {
            maxVal = pSum[i];
            maxInd = i;
        }
        if (pSum[i] < minVal) {
            minVal = pSum[i];
            minInd = i;
        }
    }
    cout << maxInd << " " << minInd << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
