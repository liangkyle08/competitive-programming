#include <bits/stdc++.h>
using namespace std;

int T, N, M;

void solve() {
    cin >> N >> M;
    vector<long long> arr(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    if (arr[M] > 0 && M != 1) {
        arr[M] = -arr[M];
        ans++;
    }
    long long leftSum = 0;
    for (int i = 1; i < M; i++) {
        leftSum += arr[i];
        if (leftSum < arr[M] || arr[i] > -arr[M]) {
            leftSum -= arr[i];
            arr[i] = -arr[i];
            leftSum += arr[i];
            ans++;
        }
    }
    long long rightSum = 0;
    for (int i = M+1; i <= N; i++) {
        rightSum += arr[i];
        if (rightSum < 0) {
            rightSum -= arr[i];
            arr[i] = -arr[i];
            rightSum += arr[i];
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
