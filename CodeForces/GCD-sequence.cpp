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
    int ind = -1;
    for (int i = 2; i < N; i++) {
        if (gcd(A[i-1], A[i]) > gcd(A[i], A[i+1])) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        cout << "YES\n";
        return;
    }
    for (int j = ind-1; j <= ind+1; j++) {
        bool flag = true;
        for (int i = 2; i < N; i++) {
            if (i == j) continue;
            if (gcd(A[(i-1 == j) ? j-1 : i-1], A[i]) > gcd(A[i], A[(i+1 == j) ? j+1 : i+1])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
            return;
        }
    }
    bool flag = true;
    for (int i = 3; i < N; i++) {
        if (gcd(A[i-1], A[i]) > gcd(A[i], A[i+1])) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "YES\n";
        return;
    }
    flag = true;
    for (int i = 2; i < N-1; i++) {
        if (gcd(A[i-1], A[i]) > gcd(A[i], A[i+1])) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
