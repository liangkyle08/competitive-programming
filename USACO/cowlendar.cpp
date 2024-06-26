#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
vector<long long> arr;
map<long long, bool> seen;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        long long v;
        cin >> v;
        if (!seen[v]) {
            arr.push_back(v);
            seen[v] = true;
        }
    }
    sort(arr.begin(), arr.end());
    long long maxLen = arr[0]/4;
    if ((int)arr.size() < 4) {
        cout << (maxLen)*(maxLen+1)/2 << "\n";
        exit(0);
    }
    set<long long> div;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            long long diff = arr[j]-arr[i];
            for (long long k = 1; k <= (long long)sqrtl(diff); k++) {
                if (diff % k == 0LL) {
                    div.insert(k);
                    div.insert(diff/k);
                }
            }
        }
    }
    long long ans = 0LL;
    for (auto L: div) {
        if (L > maxLen) continue;
        set<long long> s;
        for (auto v: arr) {
            s.insert(v % L);
        }
        if ((int)s.size() < 4) ans += L;
    }
    cout << ans << "\n";
}
