#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("nebuni.in", "r", stdin);
    // freopen("nebuni.out", "w", stdout);
    cin >> N >> M;
    vector<pair<int, int>> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i].fi >> A[i].se;
    }
    map<int, bool> L, R;
    int LCnt = 0;
    int RCnt = 0;
    long long ans = 0;
    for (auto [x, y]: A) {
        bool LFlag = false;
        bool RFlag = false;
        if (!L[x-y]) {
            L[x-y] = true;
            ans += abs(N-abs(x-y))-RCnt-1;
            LFlag = true;
        }
        if (!R[x+y]) {
            R[x+y] = true;
            ans += x+y-1-RCnt-1;
            RFlag = true;
        }
    }
}
