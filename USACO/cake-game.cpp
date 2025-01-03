#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MAX_N = 5e5;

int T, N;
long long A[MAX_N + 5];
long long P[MAX_N + 5];

void solve() {
    cin >> N;
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        total += A[i];
        P[i] = P[i - 1] + A[i];
    }
    long long ans1 = 0;
    long long ans2 = 0;
    for (int i = 0; i <= (N / 2) - 1; i++) {
        long long leftSum = P[i] - P[0];
        long long rightSum = P[N] - P[N - (N / 2 - 1) + i];
        long long midSum = total - leftSum - rightSum;
        if (leftSum + rightSum >= ans1) {
            ans1 = leftSum + rightSum;
            ans2 = midSum;
        }
    }
    cout << ans2 << " " << ans1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
