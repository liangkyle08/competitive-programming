#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[51];

void solve() {
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 2 == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
