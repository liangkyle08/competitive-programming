#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int L[100001];
int R[100001];
int cnt[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    cin >> N;
    vector<array<int, 3>> arr;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        arr.push_back({L[i], i, true});
        arr.push_back({R[i], i, false});
    }
    sort(arr.begin(), arr.end());
    set<int> s;
    int prev = arr[0][0];
    int total = 0;
    for (auto [curr, ind, flag]: arr) {
        if ((int)s.size() == 1) {
            cnt[*s.begin()] += curr-prev;
        }
        if (!s.empty()) {
            total += curr-prev;
        }
        if (flag) { // start
            s.insert(ind);
        }
        else { // end
            s.erase(ind);
        }
        prev = curr;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, total-cnt[i]);
    }
    cout << ans << '\n';
}
