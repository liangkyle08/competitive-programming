#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e4;

int N;
int A[MAX_N+5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("aranjare.in", "r", stdin);
    freopen("aranjare.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    set<pair<int, int>> s;
    s.insert({INF, INF});
    vector<vector<int>> vals;
    vector<pair<int, int>> ans;
    for (int i = N; i >= 1; i--) {
        pair<int, int> pi = *s.upper_bound({A[i], INF});
        if (pi.fi == INF) {
            vals.push_back({A[i]});
            s.insert({A[i], (int)vals.size()});
            ans.push_back({0, (int)vals.size()});
        }
        else {
            s.erase(pi);
            vals[pi.se-1].push_back(A[i]);
            s.insert({A[i], pi.se});
            ans.push_back({0, pi.se});
        }
    }
    s.erase({INF, INF});
    while (!s.empty()) {
        pair<int, int> pi = *s.begin();
        s.erase(pi);
        ans.push_back({pi.se, 0});
        vals[pi.se-1].pop_back();
        if (vals[pi.se-1].empty()) continue;
        s.insert({vals[pi.se-1].back(), pi.se});
    }
    cout << (int)vals.size()+1 << " " << (int)ans.size() << "\n";
    for (auto [u, v]: ans) {
        cout << u << " " << v << "\n";
    }
}
