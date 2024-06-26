#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
int arr[200001];

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    vector<int> prev(K+1);
    vector<multiset<int>> gaps(K+1);
    for (int i = 1; i <= N; i++) {
        gaps[arr[i]].insert(i-prev[arr[i]]-1);
        prev[arr[i]] = i;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= K; i++) {
        gaps[i].insert(N+1-prev[i]-1);
        auto it = --gaps[i].end();
        gaps[i].erase(it);
        gaps[i].insert((*it)/2);
        gaps[i].insert((*it+1)/2);
        ans = min(ans, *(--gaps[i].end()));
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
