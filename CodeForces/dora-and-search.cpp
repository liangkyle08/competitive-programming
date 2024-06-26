#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[200001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    if (N < 4) {
        cout << -1 << "\n";
        return;
    }
    int mn = 1;
    int mx = N;
    int L = 1;
    int R = N;
    while (true) {
        if (A[L] == mn) {
            L++;
            mn++;
            continue;
        }
        if (A[L] == mx) {
            L++;
            mx--;
            continue;
        }
        if (A[R] == mn) {
            R--;
            mn++;
            continue;
        }
        if (A[R] == mx) {
            R--;
            mx--;
            continue;
        }
        break;
    }
    if (R - L < 3) {
        cout << -1 << "\n";
        return;
    }
    cout << L << " " << R << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
