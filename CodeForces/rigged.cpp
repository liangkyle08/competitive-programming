#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
pair<int, int> arr[101];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    multiset<int> s;
    for (int i = 1; i <= N; i++) {
        if (arr[i].fi >= arr[1].fi) {
            s.insert(arr[i].se);
        }
    }
    bool pos = true;
    if (*(--s.end()) > arr[1].se) pos = false;
    if (s.count(arr[1].se) >= 2) pos = false;
    if (pos) {
        cout << arr[1].fi << "\n";
        return;
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
