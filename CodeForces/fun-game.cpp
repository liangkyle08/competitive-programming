#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
int A[MAX_N + 5];
int B[MAX_N + 5];

void solve() {
    cin >> N;
    string s, t;
    cin >> s >> t;
    bool flag = true;
    int ind = N + 1;
    for (int i = 1; i <= N; i++) {
        A[i] = s[i - 1] - '0';
        B[i] = t[i - 1] - '0';
        flag &= (A[i] == B[i]);
        if (A[i] == 1 && ind == N + 1) ind = i;
    }
    if (flag) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < ind; i++) {
        if (!B[i]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
