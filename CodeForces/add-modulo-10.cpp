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
    int zeroCnt = 0;
    bool same = true;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += ((A[i] % 2 == 1) ? (A[i] % 10) : 0);
        zeroCnt += (A[i] % 10 == 0);
        if (i > 1 && A[i] != A[i-1]) {
            same = false;
        }
    }
    if (same) {
        cout << "Yes\n";
        return;
    }
    if (zeroCnt >= 1) {
        cout << "No\n";
        return;
    }
    bool flag = false;
    for (int x = 2; x <= 8; x += 2) {
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            B[i] = A[i];
            while (B[i] % 10 != x) {
                B[i] += (B[i] % 10);
            }
            if ((B[i] / 10) % 2 == 0) cnt++;
        }
        if (cnt == N || cnt == 0) {
            flag = true;
        }
    }
    if (flag) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
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
