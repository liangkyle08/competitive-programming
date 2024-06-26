#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int A[1000001];
vector<int> cnt[1000001];
bool ans[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("kmajo.in", "r", stdin);
    freopen("kmajo.out", "w", stdout);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        cnt[A[i]].push_back(i);
        ans[A[i]] = false;
    }
    if (N == K) {
        for (int i = 1; i <= N; i++) {
            if ((int)cnt[A[i]].size() < (N/2)+1) continue;
            cout << A[i] << "\n";
            exit(0);
        }
        cout << -1 << "\n";
    }
    exit(0);
    for (int val = 0; val < N; val++) {
        if ((int)cnt[val].size() == 0) continue;
        vector<int> inds = cnt[val];
        int L = 0;
        int R = 0;
        while (L < (int)inds.size() && R < (int)inds.size()) {
            while ((inds[R]-inds[L]+1) > 2*K && L < (int)inds.size()) {
                L++;
            }
            if (L >= (int)inds.size()) break;
            while ((inds[R]-inds[L]+1) <= 2*K && R < (int)inds.size()) {
                if ((R-L+1) >= K/2+1) {
                    ans[val] = true;
                }
                R++;
            }
        }
    }
    vector<int> final;
    for (int val = 0; val < N; val++) {
        if (!ans[val]) continue;
        final.push_back(val);
    }
    if (final.empty()) {
        cout << -1 << "\n";
    }
    else {
        for (int i = 0; i < (int)final.size(); i++) {
            cout << final[i] << ((i < (int)final.size()) ? " " : "\n");
        }
    }
}
