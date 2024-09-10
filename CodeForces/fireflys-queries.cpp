#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N, Q;
long long A[2 * MAX_N + 5];
long long P[2 * MAX_N + 5];

void solve() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i + N] = A[i];
    }
    for (int i = 0; i < 2 * N; i++) {
        P[i] = A[(i < N ? i : i - N)] + (i > 0 ? P[i - 1] : 0);
    }
    while (Q--) {
        long long L, R;
        cin >> L >> R;
        L--; R--;
        long long leftX = L / N;
        long long rightX = R / N;
        long long ans = max(P[N - 1] * (rightX - leftX - 1), 0LL);
        if (leftX != rightX) {
            ans += P[leftX + N - 1] - (leftX + L % N - 1 >= 0 ? P[leftX + L % N - 1] : 0);
            ans += P[rightX + R % N] - (rightX - 1 >= 0 ? P[(rightX - 1) % N] : 0);
        }
        else {
            ans += P[rightX + R % N] - (leftX + L % N - 1 >= 0 ? P[leftX + L % N - 1] : 0);
        }
        cout << ans << "\n";
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
