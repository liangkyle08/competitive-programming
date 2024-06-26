#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long long K;

bool cmp(pair<long long, long long> A, pair<long long, long long> B) {
    if (A.fi*B.se == B.fi*A.se) {
        return A.se < B.se;
    }
    return A.fi*B.se > B.fi*A.se;
}

void solve() {
    cin >> N;
    vector<pair<long long, long long>> coins(N+1);
    for (int i = 1; i <= N; i++) {
        coins[i].fi = i;
        cin >> coins[i].se;
    }
    sort(coins.begin()+1, coins.end(), cmp);
    cin >> K;
    long long total = 0;
    vector<pair<long long, long long>> queries; // pos, how many
    for (int i = 1; i <= N; i++) {
        cout << coins[i].fi << " " << coins[i].se << "\n";
        queries.push_back({coins[i].fi, K/coins[i].se});
        total += K/coins[i].se;
        K = K % coins[i].se;
    }
    sort(queries.begin(), queries.end());
    reverse(queries.begin(), queries.end());
    // cout << total << "\n";
    for (int i = 1; i <= N; i++) {
        while (!queries.empty() && queries.back().fi < i) {
            total -= queries.back().se;
            cout << queries.back().fi << " " << queries.back().se << " " << total << "\n";
            queries.pop_back();
        }
        // cout << total << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
