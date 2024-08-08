#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 50;

int T, N;
int A[MAX_N + 5];

void solve() {
    cin >> N;
    map<int, int> freq;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }
    bool ans = false;
    for (auto &[val, cnt]: freq) {
        if (cnt % 2 == 0) continue;
        ans = true;
    }
    cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
