#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, G;
map<int, int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("measurement.in", "r", stdin);
    //freopen("measurement.out", "w", stdout);
    cin >> N >> G;
    multiset<int> cur;
    for (int i = 1; i <= N+1; i++) {
        cur.insert(G);
    }
    vector<pair<int, pair<int, int>>> log;
    for (int i = 1; i <= N; i++) {
        int day, id, change;
        cin >> day >> id >> change;
        A[id] = G;
        log.push_back({day, {id, change}});
    }
    sort(log.begin(), log.end());
    int curDay = -1;
    int prevMax = 0;
    int prevCnt = 0;
    set<int> prevCows;
    int curMax = 0;
    int curCnt = 0;
    set<int> curCows;
    int ans = 0;
    for (int i = 0; i < (int)log.size(); i++) {
        int day = log[i].fi;
        int id = log[i].se.fi;
        int change = log[i].se.se;
        if (day != curDay) {
            bool flag = false;
            if (prevMax != curMax) flag = true;
            if (prevMax == curMax && prevCnt != curCnt) flag = true;
            ans += flag;
            prevMax = curMax;
            prevCnt = curCnt;
        }
        cur.erase(cur.find(A[id]));
        A[id] += change;
        cur.insert(A[id]);
        curMax = *(--cur.end());
        curCnt = cur.count(curMax);
    }
    bool flag = false;
    if (prevMax != curMax) flag = true;
    if (prevMax == curMax && prevCnt != curCnt) flag = true;
    ans += flag;
    prevMax = curMax;
    prevCnt = curCnt;
    cout << ans << "\n";
}
