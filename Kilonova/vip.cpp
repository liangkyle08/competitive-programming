#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
string s, t;

void solve() {
    cin >> N >> K >> s >> t;
    map<char, int> sCnt, tCnt;
    map<char, vector<int>> ind;
    for (int i = 0; i < N; i++) {
        sCnt[s[i]]++;
    }
    for (int i = N-1; i >= 0; i--) {
        ind[s[i]].push_back(i);
    }
    int overlap = 0;
    for (int i = 0 ; i < N; i++) {
        tCnt[t[i]]++;
        if (tCnt[t[i]] <= sCnt[t[i]]) overlap++;
    }
    if (overlap < N-K) {
        cout << -1 << "\n";
        return;
    }
    int cnt = N-K;
    vector<char> ans(N, '-');
    for (char c = 'a'; c <= 'z'; c++) {
        while (cnt > 0 && !ind[c].empty() && tCnt[c] > 0) {
            ans[ind[c].back()] = c;
            // cout << ind[c].back() << " " << c << "\n";
            ind[c].pop_back();
            tCnt[c]--;
            cnt--;
        }
    }
    char cur = 'a';
    for (int i = 0; i < N; i++) {
        if (ans[i] == '-') {
            while (tCnt[cur] == 0) cur++;
            ans[i] = cur;
            tCnt[cur]--;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i];
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("vip.in", "r", stdin);
    freopen("vip.out", "w", stdout);
    cin >> T;
    while (T--) {
        solve();
    }
}
