#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
pair<pair<int, int>, int> arr[1000001]; // time arrived (a), seniority, time spent (t)

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi.fi >> arr[i].se;
        arr[i].fi.se = i;
    }
    sort(arr+1, arr+N+1);
    int curTime = 0;
    int maxWait = 0;
    int i = 1;
    set<pair<int, int>> s;
    while (i <= N) {
        while (arr[i].fi.fi <= curTime) {
            s.insert({arr[i].fi.se, i});
            i++;
        }
        if (i > N) break;
        if (s.empty()) {
            curTime = arr[i].fi.fi+arr[i].se;
            i++;
            if (i > N) break;
            continue;
        }
        int j = (*s.begin()).se;
        maxWait = max(maxWait, curTime-arr[j].fi.fi);
        curTime = max(curTime, arr[j].fi.fi)+arr[j].se;
        s.erase(s.begin());
    }
    cout << maxWait << "\n";
}
