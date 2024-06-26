#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
int A[100001];

void solve() {
    int X, Y;
    cin >> X >> Y;
    vector<pair<int, int>> ranges;
    for (int i = 1; i <= N; i++) {
        if (X <= A[i] && A[i] <= Y){
            if (i == 1 || X > A[i-1] || A[i-1] > Y) {
                ranges.push_back({0, 0});
                ranges.back().fi = i;
            }
            if (i == N || X > A[i+1] || A[i+1] > Y) {
                ranges.back().se = i;
            }
        }
    }
    long long ans = 0LL;
    for (auto [L, R]: ranges) {
        vector<int> minInd, maxInd;
        for (int i = L; i <= R; i++) {
            if (A[i] == X) minInd.push_back(i);
            if (A[i] == Y) maxInd.push_back(i);
        }
        int j = 0;
        int k = 0;
        for (int i = L; i <= R; i++) {
            if (minInd.empty() || maxInd.empty()) break;
            bool flag = false;
            while (minInd[j] < i) {
                if (j+1 == (int)minInd.size()) {
                    flag = true;
                    break;
                }
                j++;
            }
            if (flag) break;
            while (maxInd[k] < i) {
                if (k+1 == (int)maxInd.size()) {
                    flag = true;
                    break;
                }
                k++;
            }
            if (flag) break;
            int leftInd = max(minInd[j], maxInd[k]);
            int rightInd = max(minInd.back(), maxInd.back());
            ans += (rightInd-leftInd+1)+(R-rightInd);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    while (Q--) {
        solve();
    }
}
