#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("grea.in", "r", stdin);
    freopen("grea.out", "w", stdout);
    cin >> N >> K;
    string s1, s2;
    cin >> s1 >> s2;
    set<int> vals[3];
    for (int i = 1; i <= N; i++) {
        if (!(s1[i-1]-'0')) {
            vals[1].insert(i);
        }
        if (!(s2[i-1]-'0')) {
            vals[2].insert(i);
        }
    }
    int ans = INT_MAX;
    queue<array<int, 3>> q; // row, col, depth
    q.push({1, 1, 0});
    while (!q.empty()) {
        int row = q.front()[0];
        int col = q.front()[1];
        int depth = q.front()[2];
        q.pop();
        if (col == N) {
            ans = depth;
            break;
        }
        // Same Row
        if (col+1 <= N && vals[row].find(col+1) != vals[row].end()) {
            vals[row].erase(col+1);
            q.push({row, col+1, depth+1});
        }
        if (col-1 >= 1 && vals[row].find(col-1) != vals[row].end()) {
            vals[row].erase(col-1);
            q.push({row, col-1, depth+1});
        }
        // Other Row
        auto it = vals[3-row].lower_bound(max(col-K, 1));
        while (it != vals[3-row].end() && *it <= min(N, col+K)) {
            int newCol = *it;
            vals[3-row].erase(newCol);
            q.push({3-row, newCol, depth+1});
            it = vals[3-row].lower_bound(max(col-K, 1));
        }
    }
    cout << ans << '\n';
}