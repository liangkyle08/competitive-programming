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
string s;
int A[MAX_N + 5];

void solve() {
    cin >> N >> s;
    for (int i = 1; i <= N; i++) {
        A[i] = s[i - 1] - 'a' + 1;
    }
    int ans = INF;
    vector<int> prefix(N + 5), suffix(N + 5);
    for (int u = 1; u <= ALP; u++) {
        for (int v = 1; v <= ALP; v++) {
            fill(prefix.begin(), prefix.end(), 0);
            fill(suffix.begin(), suffix.end(), 0);
            for (int i = 1; i <= N; i++) {
                prefix[i] = prefix[i - 1];
                if (i % 2 == 1 && A[i] != u) prefix[i]++;
                if (i % 2 == 0 && A[i] != v) prefix[i]++;
            }
            for (int i = N; i >= 1; i--) {
                suffix[i] = suffix[i + 1];
                if (i % 2 == 1 && A[i] != v) suffix[i]++;
                if (i % 2 == 0 && A[i] != u) suffix[i]++;
            }
            if (N % 2 == 0) {
                ans = min(ans, prefix[N]);
                continue;
            }
            int cur = INF;
            for (int i = 1; i <= N; i++) {
                cur = min(prefix[i - 1] + suffix[i + 1] + 1, cur);
            }
            ans = min(ans, cur);
        }
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
