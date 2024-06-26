#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
vector<pair<int, int>> seg;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    seg.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> seg[i].fi >> seg[i].se;
    }
    sort(seg.begin(), seg.end());
    /* for (auto [u, v]: seg) {
        cout << u << " " << v << "\n";
    } */
    vector<pair<int, int>> newSeg;
    int curLeft = seg[0].fi;
    int curRight = seg[0].se;
    for (int i = 1; i < M; i++) {
        if (curRight+1 < seg[i].fi) {
            newSeg.push_back({curLeft, curRight});
            curLeft = seg[i].fi;
            curRight = seg[i].se;
            continue;
        }
        curRight = seg[i].se;
    }
    newSeg.push_back({curLeft, curRight});
    /* for (auto [u, v]: newSeg) {
        cout << u << " " << v << "\n";
    } cout << "\n"; */
    int ans = newSeg.back().se-newSeg.front().fi;
    for (int i = 0; i < (int)newSeg.size()-1; i++) {
        ans = min(ans, newSeg[i].se+(N-newSeg[i+1].fi));
    }
    cout << ans << "\n";
}
