#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, D;
pair<pair<int, int>, int> orders[100001]; // time, pos

int main() {
    freopen("ramen.in", "r", stdin);
    freopen("ramen.out", "w", stdout);
    cin >> N >> D;
    set<int> s;
    for (int i = 1; i <= N; i++) {
        cin >> orders[i].fi.se >> orders[i].fi.fi;
        orders[i].se = i;
        s.insert(orders[i].fi.se+D);
    }
    sort(orders+1, orders+N+1);
    vector<int> ans(N+1);
    for (int i = 1; i <= N; i++) {
        auto it = s.lower_bound(orders[i].fi.se-orders[i].fi.fi);
        ans[orders[i].se] = *it+orders[i].fi.fi;
        s.erase(it);
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}
