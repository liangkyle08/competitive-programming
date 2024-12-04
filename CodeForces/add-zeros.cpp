#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 3e5;

int T, N;
long long A[MAX_N + 5];

void solve() {
    cin >> N;
    vector<pair<long long, int>> arr;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        arr.push_back({A[i] + i - 1, i});
    }
    sort(arr.begin(), arr.end());
    set<long long> s;
    s.insert(N);
    for (auto &[val, ind]: arr) {
        if (s.find(val) == s.end()) continue;
        s.insert(val + ind - 1);
    }
    cout << *(--s.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
