#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
pair<int, int> arr[2501];
long long prefixSums[2501][2501];

bool cmp(pair<int, int> A, pair<int, int> B) {
    return A.se < B.se;
}

long long getSum(int x1, int y1, int x2, int y2) {
    return prefixSums[x2][y2]-prefixSums[x1-1][y2]-prefixSums[x2][y1-1]+prefixSums[x1-1][y1-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    sort(arr+1, arr+N+1);
    for (int i = 1; i <= N; i++) {
        arr[i].fi = i;
    }
    sort(arr+1, arr+N+1, cmp);
    for (int i = 1; i <= N; i++) {
        arr[i].se = i;
    }
    for (int i = 1; i <= N; i++) {
        prefixSums[arr[i].fi][arr[i].se] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefixSums[i][j] += prefixSums[i-1][j]+prefixSums[i][j-1]-prefixSums[i-1][j-1];
        }
    }
    long long ans = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = a; b <= N; b++) {
            ans += getSum(1, a, min(arr[a].fi, arr[b].fi), b)*getSum(max(arr[a].fi, arr[b].fi), a, N, b);
        }
    }
    cout << ans+1 << "\n";
}
