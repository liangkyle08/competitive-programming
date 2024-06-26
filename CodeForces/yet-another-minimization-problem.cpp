#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[101];
int B[101];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    int aSum = 0;
    int bSum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            aSum += (int)pow(A[i]+A[j], 2);
            bSum += (int)pow(B[i]+B[j], 2);
        }
    }
    for (int j = 1; j <= N; j++) {
        int aSum2 = aSum;
        int bSum2 = bSum;
        for (int i = 1; i <= N; i++) {
            if (i == j) continue;
            aSum2 -= (int)pow(A[i]+A[j], 2);
            bSum2 -= (int)pow(B[i]+B[j], 2);
            aSum2 += (int)pow(A[i]+B[j], 2);
            bSum2 += (int)pow(B[i]+A[j], 2);
        }
        if (aSum2+bSum2 > aSum+bSum) {
            aSum = aSum2;
            bSum = bSum2;
        }
    }
    cout << aSum+bSum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
