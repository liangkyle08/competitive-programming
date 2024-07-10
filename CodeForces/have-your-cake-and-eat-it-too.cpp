#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
int A[4][MAX_N+5];
long long pSum[4][MAX_N+5];
vector<array<int, 3>> pos = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1}
};

void solve() {
    cin >> N;
    long long total = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            total += A[i][j];
            pSum[i][j] = pSum[i][j-1] + A[i][j];
        }
    }
    long long upperBound = ((total / 3) + 2) / 3;
    vector<int> ans(6);
    bool flag = true;
    for (auto [a, b, c]: pos) {
        int i = 1;
        while (pSum[a][i] < upperBound && i < N) {
            i++;
        }
        int j = i+1;
        while (pSum[b][j] - pSum[b][i] < upperBound && j < N) {
            j++;
        }
        int k = j+1;
        while (pSum[c][k] - pSum[c][j] < upperBound && k < N) {
            k++;
        }
        if (pSum[a][i] >= upperBound
            && (pSum[b][j] - pSum[b][i]) >= upperBound
            && (pSum[c][k] - pSum[c][j]) >= upperBound
            && i <= N
            && j <= N
            && k <= N) {
            flag = false;
            ans[2*(a-1)] = 1;
            ans[2*(a-1)+1] = i;
            ans[2*(b-1)] = i+1;
            ans[2*(b-1)+1] = j;
            ans[2*(c-1)] = j+1;
            ans[2*(c-1)+1] = k;
        }
    }
    if (flag) {
        cout << -1 << "\n";
        return;
    }
    for (auto v: ans) {
        cout << v << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
