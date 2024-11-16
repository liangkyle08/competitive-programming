#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 50;

int T, N;
int A[MAX_N + 5];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (abs(A[i] - A[i - 1]) == 5) cnt++;
        if (abs(A[i] - A[i - 1]) == 7) cnt++;
    }
    cout << (cnt == N - 1 ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
