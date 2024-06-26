#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, Q;

void solve() {
    vector<pair<int, pair<int, int>>> arr;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        arr.push_back({l, {0, i}}); // Start
        arr.push_back({b, {2, i}}); // End
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int x;
        cin >> x;
        arr.push_back({x, {1, i}});
    }
    sort(arr.begin(), arr.end());
    set<int> s;
    stack<int> cur;
    vector<int> ans(Q+1);
    int curPos = 0;
    for (auto [u, pi]: arr) {
        switch (pi.fi) {
            case 0:
                s.insert(pi.se);
                curPos = u;
                break;
            case 1:
                cur.push(pi.se);
                curPos = u;
                if (s.empty()) {
                    ans[cur.top()] = curPos;
                    cur.pop();
                }
                break;
            case 2:
                s.erase(pi.se);
                curPos = u;
                if (s.empty()) {
                    while (!cur.empty()) {
                        ans[cur.top()] = curPos;
                        cur.pop();
                    }
                }
        }
    }
    for (int i = 1; i <= Q; i++) {
        cout << ans[i] << " ";
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
