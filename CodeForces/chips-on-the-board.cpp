#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long long A[300001];
long long B[300001];

void solve() {
    cin >> N;
    long long aMin = (1LL<<60);
    long long aSum = 0LL;
    long long bMin = (1LL<<60);
    long long bSum = 0LL;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        aMin = min(aMin, A[i]);
        aSum += A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        bMin = min(bMin, B[i]);
        bSum += B[i];
    }
    cout << min(N*aMin+bSum, N*bMin+aSum) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
