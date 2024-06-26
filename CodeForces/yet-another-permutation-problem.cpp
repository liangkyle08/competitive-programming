#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

void solve() {
    cin >> N;
    vector<int> ans;
    vector<bool> seen(N+1);
    for (int i = 1; 2*i <= N; i++) {
        while (!ans.empty() && ans.back()*2 <= N && !seen[ans.back()*2]) {
            seen[ans.back()*2] = true;
            ans.push_back(ans.back()*2);
        }
        if (seen[i]) continue;
        ans.push_back(i);
        ans.push_back(i*2);
        seen[i] = true;
        seen[i*2] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (!seen[i]) ans.push_back(i);
    }
    for (auto v: ans) {
        cout << v << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
