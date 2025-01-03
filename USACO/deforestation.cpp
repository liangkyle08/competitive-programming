#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int INF = (1 << 30);

const int MAX_N = 1e5;
const int MAX_K = 1e5;

int T, N, K;
int mn[MAX_K + 5];
int mx[MAX_K + 5];

void solve() {
    cin >> N >> K;
    vector<array<int, 3>> arr; // position and type (0 = end, 1 = start, 2 = item)
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        arr.push_back({x, 2, -1});
    }
    for (int i = 1; i <= K; i++) {
        int l, r;
        cin >> l >> r >> mn[i];
        arr.push_back({l, 1, i});
        arr.push_back({r + 1, 0, i});
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for (auto &[pos, t, ind]: arr) {
        if (t == 2) cnt++;
        if (t == 0) mx[ind] = cnt;
    }
    multiset<int> s;
    int skip = 0;
    int cnt2 = 0;
    for (auto &[pos, t, ind]: arr) {
        if (t == 2) {
            cnt2++;
            int curMax = (!s.empty() ? *s.begin() : INF);
            if (skip < curMax) skip++;
        }
        if (t == 1) {
            mx[ind] = (mx[ind] - cnt2) - mn[ind] + skip;
            s.insert(mx[ind]);
        }
        if (t == 0) {
            s.erase(s.find(mx[ind]));
        }
    }
    cout << skip << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
