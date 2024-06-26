#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
long long T[300005];
long long in[300005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
    }
    vector<long long> minTime(N+5, (1LL<<60));
    multiset<pair<long long, int>> s;
    for (int i = 1; i <= K; i++) {
        minTime[i] = 0;
        s.insert({minTime[i] + T[i], i});
    }
    for (int i = K+1; i <= N+1; i++) {
        minTime[i] = (*s.begin()).fi;
        in[i] = (*s.begin()).se;
        s.erase(s.begin());
        s.insert({minTime[i] + T[i], i});
    }
    int ind = N+1;
    set<long long> key;
    key.insert(minTime[ind]);
    while (in[ind] > 1) {
        ind = in[ind];
        key.insert(minTime[ind]);
    }
    vector<long long> curTime(N+5, (1LL<<60));
    multiset<pair<long long, int>> s2;
    vector<bool> ans(K+1);
    for (int i = 1; i <= K; i++) {
        curTime[i] = 0;
        if (key.find(curTime[i]+T[i]) != key.end()) {
            ans[i] = true;
        }
        s2.insert({curTime[i] + T[i], i});
    }
    for (int i = K+1; i <= N+1; i++) {
        curTime[i] = (*s2.begin()).fi;
        int val = (*s2.begin()).se;
        if (key.find(curTime[i]+T[i]) != key.end()) {
            ans[val] = true;
        }
        s2.erase(s2.begin());
        s2.insert({curTime[i] + T[i], val});
    }
    cout << minTime[N+1] << "\n";
    for (int i = 1; i <= K; i++) {
        cout << ans[i];
    } cout << "\n";
}