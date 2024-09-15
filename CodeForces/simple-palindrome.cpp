#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, N;

void solve() {
    cin >> N;
    vector<int> cnt(5);
    for (int i = 0; i < N; i++) {
        cnt[i % 5]++;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << "aeiou"[i];
        }
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
