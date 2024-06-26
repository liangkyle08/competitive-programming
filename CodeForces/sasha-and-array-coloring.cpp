// Codeforces Round 881 (Div. 3)
// A. Sasha and Array Coloring
// https://codeforces.com/contest/1843/problem/A

#include <bits/stdc++.h>
using namespace std;

int T, N;

void solve() {
    cin >> N;
    vector<int> arr(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 1; i <= N/2; i++) {
        ans += arr[N-i+1]-arr[i];
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
