#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, K, N, M;
string S, T;

void solve1() {
    map<char, int> sCnt, tCnt;
    for (int i = 0; i < N; i++) {
        sCnt[S[i]]++;
    }
    for (int i = 0; i < M; i++) {
        tCnt[T[i]]++;
    }
    int cnt = 0;
    map<char, char> key;
    for (char c = 'a'; c <= 'z'; c++) {
        if (sCnt[c] == 0 && tCnt[c] == 0) continue;
        cnt++;
        key[c] = (tCnt[c] >= sCnt[c]) ? 'T' : 'S';
    }
    cout << cnt << "\n";
    for (auto [u, v]: key) {
        cout << u << " " << v << "\n";
    }
}

void solve2() {
    vector<map<char, int>> charCnt;
    vector<int> cnt;
    for (int i = 0; i < N; i++) {
        if (i == 0 || S[i-1] > S[i]) {
            charCnt.push_back(map<char, int>());
            cnt.push_back(0);
        }
        charCnt.back()[S[i]]++;
        cnt.back()++;
    }
    int j = 0;
    for (int i = 0; i < M; i++) {
        if (charCnt[j][T[i]]) {
            charCnt[j][T[i]]--;
            cnt[j]--;
        }
        if (cnt[j] == 0) j++;
        if (j >= (int)cnt.size()) break;
    }
    if (cnt.back() > 0) {
        cout << "NU\n";
    }
    else {
        cout << "DA\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("opsir.in", "r", stdin);
    freopen("opsir.out", "w", stdout);
    cin >> C >> K;
    while (K--) {
        cin >> N >> M;
        cin >> S >> T;
        if (C == 1) solve1();
        else solve2();
    }
}
