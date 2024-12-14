#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, P;
vector<int> tubes[3];
vector<pair<int, int>> moves;

vector<int> compressString(string s) {
    vector<int> arr;
    for (int i = 0; i < (int)s.size(); i++) {
        if (!arr.empty() && arr.back() == s[i]) continue;
        arr.push_back(s[i]);
    }
    return arr;
}

void move(int src, int dst) {
    moves.push_back({src, dst});
    if (tubes[dst].empty() || tubes[dst].back() != tubes[src].back()) {
        tubes[dst].push_back(tubes[src].back());
    }
    tubes[src].pop_back();
}

void solve() {
    cin >> N >> P;
    string f, s;
    cin >> f >> s;
    tubes[0] = compressString(f);
    tubes[1] = compressString(s);
    tubes[2].clear();
    moves.clear();
    if (tubes[0][0] == tubes[1][0]) tubes[0].insert(tubes[0].begin(), tubes[0][0] ^ 3);
    int ans = (int)tubes[0].size() + (int)tubes[1].size() - 2;
    if (ans > 1) ans++;
    cout << ans << "\n";
    if (P == 1) return;
    if (tubes[0].back() == tubes[1].back()) {
        if ((int)tubes[0].size() > (int)tubes[1].size()) {
            move(0, 1);
        }
        else {
            move(1, 0);
        }
    }
    for (int i = 0; i < 2; i++) {
        if ((int)tubes[i].size() > 1) {
            move(i, 2);
            int id = 0;
            if (tubes[id][0] == tubes[2][0]) id ^= 1;
            while ((int)tubes[id].size() > 1) {
                if (tubes[id].back() == tubes[2][0]) {
                    move(id, 2);
                }
                else {
                    move(id, id ^ 1);
                }
            }
            id ^= 1;
            while ((int)tubes[id].size() > 1) {
                if (tubes[id].back() == tubes[2][0]) {
                    move(id, 2);
                }
                else {
                    move(id, id ^ 1);
                }
            }
            move(2, id);
        }
    }
    for (auto &[u, v]: moves) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> T;
    while (T--) {
        solve();
    }
}
