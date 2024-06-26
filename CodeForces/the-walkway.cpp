#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M, D;

void solve() {
    cin >> N >> M >> D;
    vector<int> arr(M+5);
    for (int i = 1; i <= M; i++) {
        cin >> arr[i];
    }
    int numEaten = M;
    if (arr[1] != 1) numEaten++;
    for (int i = 1; i <= M; i++) {
        if (i == 1) {
            numEaten += (arr[i]-2)/D;
        }
        else {
            numEaten += (arr[i]-arr[i-1]-1)/D;
        }
    }
    numEaten += (N-arr[M])/D;
    vector<int> diff(M+1);
    int maxDiff = -(1<<30);
    for (int i = 1; i <= M; i++) {
        int prev = 1;
        int next = N+1;
        if (i > 1) {
            prev = arr[i-1];
        }
        if (i < M) {
            next = arr[i+1];
        }
        int curVal = (next-arr[i]-1)/D + (arr[i]-prev-1)/D + 1;
        if (arr[i] == 1) curVal--;
        int newVal = (next-prev-1)/D;
        diff[i] = curVal-newVal;
        if (diff[i] > maxDiff) {
            maxDiff = diff[i];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= M; i++) {
        if (diff[i] == maxDiff) {
            cnt++;
        }
    }
    cout << numEaten-maxDiff << " " << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
