#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long A[301][301];
long long B[301];

bool check(int i) {
    long long mx = -(1LL<<60);
    long long mn = (1LL<<60);
    for (int j = i; j <= N; j++) {
        mx = max(mx, B[j]);
        mn = min(mn, B[j]);
        if (mx-mn != A[i][j]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = N-1; i >= 1; i--) {
        B[i] = B[i+1]+A[i][i+1];
        if (check(i)) continue;
        B[i] = B[i+1]-A[i][i+1];
    }
    for (int i = 1; i <= N; i++) {
        cout << B[i] << (i < N ? " " : "\n");
    }
}
