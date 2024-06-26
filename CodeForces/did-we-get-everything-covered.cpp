#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K, M;
string s;

void solve() {
    cin >> N >> K >> M >> s;
    map<char, vector<int>> inds;
    for (int i = M-1; i >= 0; i--) {
        inds[s[i]].push_back(i);
    }
    string t = "";
    bool flag = true;
    char extra = '#';
    int curInd = -1;
    while (flag) {
        int nxtInd = -1;
        int chr = '#';
        for (char c = 'a'; (c - 'a') < K; c++) {
            while (!inds[c].empty() && inds[c].back() <= curInd) {
                inds[c].pop_back();
            }
            if (inds[c].empty()) {
                flag = false;
                extra = c;
                break;
            }
            if (inds[c].back() > nxtInd) {
                nxtInd = inds[c].back();
                chr = c;
            }
        }
        if (!flag || chr == '#') break;
        curInd = nxtInd;
        t += chr;
    }
    if ((int)t.size() >= N) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
        if (extra == '#') extra = 'a';
        while ((int)t.size() < N) {
            t += extra;
        }
        cout << t << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
