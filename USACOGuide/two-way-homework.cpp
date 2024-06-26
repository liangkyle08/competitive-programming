#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long A[100005];
long long B[100005];
long long suffixSum[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    long long sum = min(A[N], B[N]);
    for (int i = N-1; i >= 1; i--) {
        sum = min(A[i]+2*sum, B[i]+sum);
    }
    cout << sum << "\n";
}
