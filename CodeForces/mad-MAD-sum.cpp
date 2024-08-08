#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
long long A[MAX_N + 5];
long long B[MAX_N + 5];
long long C[MAX_N + 5];

void solve() {
    cin >> N;
    vector<int> freqA(N + 5), freqB(N + 5);
    long long maxA = 0;
    long long maxB = 0;
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        freqA[A[i]]++;
        if (freqA[A[i]] >= 2 && A[i] > maxA) {
            maxA = A[i];
        }
        sum += A[i];
        B[i] = maxA;
        freqB[B[i]]++;
        if (freqB[B[i]] >= 2 && B[i] > maxB) {
            maxB = B[i];
        }
        sum += B[i];
        C[i] = maxB;
    }
    for (int i = N; i >= 1; i--) {
        sum += (long long)(N - i + 1) * C[i];
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
