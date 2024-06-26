#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long long X, Y;

void solve() {
    cin >> X >> Y >> N;
    vector<long long> arr(N+1);
    arr[N] = Y;
    long long B = 1;
    for (int i = N-1; i >= 1; i--) {
        arr[i] = arr[i+1]-B;
        B++;
    }
    if (arr[1] < X) {
        cout << -1 << "\n";
    }
    else {
        arr[1] = X;
        for (int i = 1; i <= N; i++) {
            cout << arr[i] << " ";
        } cout << "\n";
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
