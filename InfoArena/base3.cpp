#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int MX = 100000;
const int MID = 50000;

long long arr[3];
long long len[MX+1];
bool seen[MX+1];

int main() {
    freopen("base3.in", "r", stdin);
    freopen("base3.out", "w", stdout);
    for (auto &v: len) v = (1LL<<60);
    for (auto &v: arr) {
        string s;
        cin >> s;
        v = (long long)s.size();
        for (int i = 0; i < v; i++) {
            if (s[i] == '1') {
                long long a = i;
                long long b = v-i-1;
                len[a-b+MID] = min(len[a-b+MID], v);
            }
        }
    }
    priority_queue<pair<long long, long long>> pq;
    for (int i = 0; i <= MX; i++) {
        if (len[i] != (1LL<<60)) {
            pq.emplace(-len[i], i);
        }
    }
    while (!pq.empty()) {
        long long u = pq.top().se;
        pq.pop();
        if (seen[u]) continue;
        seen[u] = true;
        for (auto v: arr) {
            if (u-v >= 0LL && len[u]+v < len[u-v]) {
                len[u-v] = len[u]+v;
                pq.emplace(-len[u-v], u-v);
            }
            if (u+v <= MX && len[u]+v < len[u+v]) {
                len[u+v] = len[u]+v;
                pq.emplace(-len[u+v], u+v);
            }
        }
    }
    if (len[MID] == (1LL<<60)) {
        cout << 0 << "\n";
    }
    else {
        cout << len[MID] << "\n";
    }
}
