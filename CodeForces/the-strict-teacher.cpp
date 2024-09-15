#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_M = 1e5;

int T, N, M, Q;
int B[MAX_M + 5];
int A[MAX_M + 5];

void solve() {
    cin >> N >> M >> Q;
    set<int> s;
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
        s.insert(B[i]);
    }
    s.insert(-INF); s.insert(INF);
    for (int i = 1; i <= Q; i++) {
        cin >> A[i];
        int L = *(--s.upper_bound(A[i]));
        int R = *(s.lower_bound(A[i]));
        if (L != -INF && R != INF) {
            cout << (R - L) / 2 << "\n";
            continue;
        }
        if (R != INF) {
            cout << R - 1 << "\n";
        }
        if (L != -INF) {
            cout << N - L << "\n";
        }
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
