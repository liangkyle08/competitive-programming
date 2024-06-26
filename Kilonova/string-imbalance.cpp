#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, Q;
long long F;
char C;

void solve2(multiset<long long> cnt, int K) {
    while (K > 0) {
        if ((int)cnt.size() <= 1) break;
        long long L = *cnt.begin();
        cnt.erase(cnt.begin());
        long long R = *(--cnt.end());
        cnt.erase(--cnt.end());
        if (L > K) {
            cnt.insert(R+K);
            cnt.insert(L-K);
            K = 0;
        }
        else {
            cnt.insert(R+L);
            K -= L;
        }
    }
    long long total = 0;
    for (auto v: cnt) {
        total += v;
    }
    long long ans = 0;
    for (auto v: cnt) {
        total -= v;
        ans += total*v;
    }
    cout << ans << "\n";
}

void solve() {
    int K;
    map<char, long long> freq;
    multiset<long long> cnt;
    cin >> Q;
    while (Q--) {
        cin >> F >> C >> K;
        if (freq[C]) {
            cnt.erase(cnt.find(freq[C]));
        }
        freq[C] += F;
        cnt.insert(freq[C]);
        solve2(cnt, K);
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
