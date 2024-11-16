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
int A[MAX_N + 5];
int B[MAX_N + 5];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    int mx = -1;
    int mn = INF;
    for (int i = 1; i <= N; i++) {
        if (A[i] > B[i]) swap(A[i], B[i]);
        mx = max(mx, A[i]);
        mn = min(mn, B[i]);
    }
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        total += abs(A[i] - B[i]);
    }
    total += 2 * max(mx - mn, 0);
    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
