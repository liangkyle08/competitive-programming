#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 5000;
const int MAX_A = 1e6;

int N, Q;
int A[MAX_N + 5];
long long ans[MAX_N + 5][MAX_N + 5];
int freq[2 * MAX_A + 5];

int conv(int x) {
    return x + MAX_A;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = N; i >= 1; i--) {
        memset(freq, 0, sizeof(freq));
        for (int j = i + 1; j <= N; j++) {
            int cur = conv(-A[i] - A[j]);
            if (0 <= cur && cur <= 2 * MAX_A) {
                ans[i][j] = freq[cur];
            }
            freq[conv(A[j])]++;
        }
    }
    for (int i = N; i >= 1; i--) {
        for (int j = i + 1; j <= N; j++) {
            ans[i][j] += ans[i + 1][j] + ans[i][j - 1] - ans[i + 1][j - 1];
        }
    }
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << ans[a][b] << "\n";
    }
}
