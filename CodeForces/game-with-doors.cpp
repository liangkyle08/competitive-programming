#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

int T, left1, left2, right1, right2;
int A[105];

void solve() {
    cin >> left1 >> right1 >> left2 >> right2;
    memset(A, 0, sizeof(A));
    for (int i = 2; i <= 100; i++) {
        if ((left1 <= i && i <= right1) && (left2 <= (i - 1) && (i - 1) <= right2)) {
            A[i] = true;
        }
        if ((left2 <= i && i <= right2) && (left1 <= (i - 1) && (i - 1) <= right1)) {
            A[i] = true;
        }
    }
    int ans = 0;
    for (int i = 2; i <= 100; i++) {
        ans += A[i];
    }
    cout << max(ans, 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
