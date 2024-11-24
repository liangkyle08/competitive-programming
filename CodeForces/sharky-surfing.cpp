#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N, M, Q;

void solve() {
    cin >> N >> M >> Q;
    vector<array<int, 3>> arr;
    for (int i = 1; i <= N; i++) {
        int L, R;
        cin >> L >> R;
        arr.push_back({L, R, 1});
    }
    for (int i = 1; i <= M; i++) {
        int x, v;
        cin >> x >> v;
        arr.push_back({x, v, 2});
    }
    sort(arr.begin(), arr.end());
    priority_queue<int> pq;
    int power = 1;
    int ans = 0;
    for (auto &[u, v, t]: arr) {
        if (t == 2) {
            pq.push(v);
            continue;
        }
        while (power < (v - u + 2) && !pq.empty()) {
            power += pq.top();
            ans++;
            pq.pop();
        }
        if (power < (v - u + 2)) {
            ans = -1;
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
