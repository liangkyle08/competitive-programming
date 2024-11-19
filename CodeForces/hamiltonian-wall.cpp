#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
int A[2][MAX_N + 5];

void solve() {
    cin >> N;
    string c1, c2;
    cin >> c1 >> c2;
    for (int i = 1; i <= N; i++) {
        A[0][i] = c1[i - 1] == 'B';
        A[1][i] = c2[i - 1] == 'B';
    }
    bool cur1 = A[0][1];
    bool cur2 = A[1][1];
    for (int i = 2; i <= N; i++) {
        if (A[0][i] && A[1][i]) {
            swap(cur1, cur2);
        }
        if (A[0][i] && !A[1][i]) {
            cur2 = false;
        }
        if (!A[0][i] && A[1][i]) {
            cur1 = false;
        }
    }
    cout << (cur1 || cur2 ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
