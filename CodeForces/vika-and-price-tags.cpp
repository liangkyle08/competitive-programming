#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[100001];
int B[100001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 1) {
                cout << A[j] << " ";
                continue;
            }
            int diff = abs(A[j]-B[j]);
            cout << B[j] << " ";
            A[j] = B[j];
            B[j] = diff;
        } cout << "\n";
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
        cout << "~~~~~\n";
    }
}
