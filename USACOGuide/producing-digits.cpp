#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[500001];
int B[500001];
int mul[10][10];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] = abs(A[i]) % 10;
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    vector<bool> prev(10);
    for (int i = 1; i <= N; i++) {
        bool flag = false;
        vector<bool> cur(10);
        for (int j = 0; j < 10; j++) {
            if (prev[j]) {
                cur[mul[A[i]][j]] = true;
            }
        }
        cur[A[i]] = true;
        if (cur[B[i]]) {
            cout << "Y";
        }
        else {
            cout << "N";
        }
        for (int j = 0; j < 10; j++) {
            if (cur[j]) {
                prev[j] = true;
            }
        }
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mul[i][j] = (i * j) % 10;
        }
    }
    cin >> T;
    while (T--) {
        solve();
    }
}
