#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
long long K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    vector<pair<int, int>> arr(N); // weight, number of cows
    for (int i = 0; i < N; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    sort(arr.begin(), arr.end(), greater<pair<int, int>>());
    deque<pair<int, int>> towers;
    towers.push_back({INT_MAX, M});
    long long ans = 0;
    for (auto &[w, a]: arr) {
        int remaining = a;
        while (!towers.empty() && remaining > 0 && w+K <= towers.front().fi) {
            if (towers.front().se > remaining) {
                towers.front().se -= remaining;
                remaining = 0;
            }
            else {
                remaining -= towers.front().se;
                towers.pop_front();
            }
        }
        int cnt = a-remaining;
        if (cnt > 0) {
            towers.push_back({w, cnt});
            ans += cnt;
        }
    }
    cout << ans << "\n";
}