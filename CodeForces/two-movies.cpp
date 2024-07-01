#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[200001];
int B[200001];

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
        if (A[i] == B[i]) continue;
        if (A[i] > B[i]) {
            aSum += A[i];
        }
        else {
            bSum += B[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        if (A[i] != B[i]) continue;
        if (A[i] == 1) {
            if (aSum < bSum) {
                aSum += A[i];
            }
            else {
                bSum += B[i];
            }
        }
        if (A[i] == -1) {
            if (aSum > bSum) {
                aSum += A[i];
            }
            else {
                bSum += B[i];
            }
        }
    }
    cout << min(aSum, bSum) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
