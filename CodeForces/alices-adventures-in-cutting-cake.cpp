#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;
const int MAX_M = 2e5;

int T;
int N, M, V;
int A[MAX_N + 5];
int prefix[MAX_N + 5];
int suffix[MAX_N + 5];
long long sums[MAX_N + 5];

void solve() {
    cin >> N >> M >> V;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sums[i] = sums[i - 1] + A[i];
    }
    vector<int> left(N + 5, N + 1), right(N + 5, -1);
    prefix[0] = 0;
    left[0] = -1;
    long long pSum = 0;
    for (int i = 1; i <= N; i++) {
        pSum += A[i];
        prefix[i] = prefix[i - 1];
        if (pSum >= V) {
            prefix[i]++;
            pSum = 0;
        }
        left[prefix[i]] = min(left[prefix[i]], i);
    }
    suffix[N + 1] = 0;
    long long sSum = 0;
    right[0] = N + 1;
    for (int i = N; i >= 1; i--) {
        sSum += A[i];
        suffix[i] = suffix[i + 1];
        if (sSum >= V) {
            suffix[i]++;
            sSum = 0;
        }
        right[suffix[i]] = max(right[suffix[i]], i);
    }
    long long ans = -1;
    for (int i = 0; i <= M; i++) {
        if (left[i] + 1 > right[M - i] - 1) continue;
        ans = max(ans, sums[right[M - i] - 1] - sums[left[i]]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
