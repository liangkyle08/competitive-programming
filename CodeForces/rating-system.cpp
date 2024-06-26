// Educational Codeforces Round 151 (Rated for Div. 2)
// D. Rating System
// https://codeforces.com/contest/1845/problem/D

// Not Done

#include <bits/stdc++.h>
using namespace std;

int T, N;

void solve() {
    cin >> N;
    vector<int> arr(N+1);
    vector<int> prefixSum(N+1);
    vector<int> upperSum(N+2);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefixSum[i] = prefixSum[i-1]+arr[i];
        upperSum[i] = max(0, upperSum[i-1]+arr[i]);
    }
    long long ans = 0;
    long long finalVal = 0;
    for (int i = 1; i <= N; i++) {
        if (prefixSum[i]+max(0, upperSum[N])*(i < N) > finalVal) {
            ans = prefixSum[i];
            finalVal = prefixSum[i]+max(0, upperSum[N])*(i < N);
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
