#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
vector<pair<long long, int>> X;

void solve() {
    cin >> N;
    X.clear();
    X.resize(N+1);
    for (int i = 1; i <= N; i++) {
        X[i].se = i;
        cin >> X[i].fi;
    }
    sort(X.begin()+1, X.end());
    vector<long long> ans(N+1);
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            for (int j = 1; j <= N; j++) {
                ans[X[i].se] += abs(X[j].fi-X[i].fi)+1;
            }
        }
        else {
            ans[X[i].se] = ans[X[i-1].se];
            long long diff = X[i].fi-X[i-1].fi;
            ans[X[i].se] += (i-1)*diff;
            ans[X[i].se] -= (N-i+1)*diff;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
