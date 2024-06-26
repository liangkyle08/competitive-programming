#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[80001];

void solve() {
    cin >> N;
    set<int> s;
    int maxVal = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    map<int, map<int, int>> GCD;
    vector<bool> seen(maxVal+1);
    for (int u = 2; u <= maxVal; u++) {
        if (seen[u]) continue;
        for (int v = u; v <= maxVal; v += u) {
            seen[v] = true;
            if (s.find(v) != s.end()) {
                GCD[u][v] = u;
                GCD[v][u] = u;
                cout << u << " " << v << " " << GCD[u][v] << "\n";
            }
        }
    }
    sort(arr+1, arr+N+1);
    long long ans = 0;
    for (int i = 2; i < N; i++) {
        long long cur = 0;
        for (int j = 1; j < i; j++) {
            cur += max(GCD[arr[i]][arr[j]], 1);
        }
        ans += cur*(N-i);
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
