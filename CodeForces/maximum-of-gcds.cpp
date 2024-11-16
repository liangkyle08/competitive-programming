#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int T, N;
int logs[MAX_N + 5];
int A[MAX_N + 5];
int rmq[20][MAX_N + 5];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        rmq[0][i] = A[i];
    }
    for (int layer = 1; layer <= logs[N]; layer++) {
        for (int pos = 1; pos + (1 << layer) - 1 <= N; pos++) {
            rmq[layer][pos] = gcd(rmq[layer - 1][pos], rmq[layer - 1][pos + (1 << (layer - 1))]);
        }
    }
    vector<int> ans(N + 5);
    for (int i = 1; i <= N; i++) {
        int pos = i;
        int val = A[i];
        while (pos <= N) {
            int L = pos;
            int R = N;
            int lastEqual = L;
            while (L <= R) {
                int mid = (L + R) / 2;
                int layer = logs[mid - i + 1];
                int div = gcd(rmq[layer][i], rmq[layer][mid - (1 << layer) + 1]);
                if (div == val) {
                    lastEqual = mid;
                    L = mid + 1;
                }
                else {
                    R = mid - 1;
                }
            }
            ans[lastEqual - i + 1] = max(ans[lastEqual - i + 1], val);
            if (lastEqual < N) {
                int layer = logs[lastEqual - i + 2];
                val = gcd(rmq[layer][i], rmq[layer][lastEqual - (1 << layer) + 2]);
            }
            pos = lastEqual + 1;
        }
    }
    for (int i = N - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i <= MAX_N; i++) {
        logs[i] = logs[i / 2] + 1;
    }
    cin >> T;
    while (T--) {
        solve();
    }
}
