#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;

void solve() {
    cin >> N;
    vector<multiset<int>> arr(N+1);
    for (int i = 1; i <= N; i++) {
        arr[i].clear();
        cin >> M;
        for (int j = 1; j <= M; j++) {
            int v;
            cin >> v;
            arr[i].insert(v);
        }
    }
    multiset<int> A, B;
    for (int i = 1; i <= N; i++) {
        A.insert(*arr[i].begin());
        arr[i].erase(arr[i].begin());
        B.insert(*arr[i].begin());
    }
    B.erase(B.begin());
    B.insert(*A.begin());
    long long ans = 0LL;
    for (auto v: B) {
        ans += v;
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
