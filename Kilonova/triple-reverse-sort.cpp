#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[200001];

void solve() {
    cin >> N;
    bool pos = true;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if ((i % 2) != (arr[i] % 2)) {
            pos = false;
        }
    }
    if (pos) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
