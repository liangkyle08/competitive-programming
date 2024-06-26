// Codeforces Round 881 (Div. 3)
// B. Long Long
// https://codeforces.com/contest/1843/problem/B

#include <bits/stdc++.h>
using namespace std;

int T, N;

void solve() {
    cin >> N;
    vector<int> arr(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    long long sum = 0;
    int cnt = 0;
    bool flag = true;
    for (int i = 1; i <= N; i++) {
        if (flag) {
            if (arr[i] < 0) {
                cnt++;
                flag = false;
            }
        }
        else {
            if (arr[i] > 0) {
                flag = true;
            }
        }
        sum += abs(arr[i]);
    }
    cout << sum << " " << cnt << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
