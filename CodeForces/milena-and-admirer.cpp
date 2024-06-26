#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[200001];

void solve() {
    cin >> N;
    stack<int> s;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s.push(arr[i]);
    }
    int ans = 0;
    int prev = (1<<30);
    while (!s.empty()) {
        if (s.top() <= prev) {
            prev = s.top();
            s.pop();
            continue;
        }
        int curr = s.top();
        s.pop();
        if (curr >= 2*prev) {
            int cnt = max((curr-prev)/prev, 0);
            ans += cnt;
            curr -= cnt*prev;
            if (cnt > 0) {
                s.push(curr);
                continue;
            }
        }
        s.push(curr/2);
        s.push(curr-(curr/2));
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}