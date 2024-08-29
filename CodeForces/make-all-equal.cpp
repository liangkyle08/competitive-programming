#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 100;

int T, N;
int A[MAX_N + 5];

void solve() {
    cin >> N;
    map<int, int> freq;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }
    int ans = INF;
    for (auto &[val, cnt]: freq) {
        ans = min(ans, N - cnt);
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
