#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int N, K, Q, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K >> Q;
    vector<vector<long long>> A(N + 5, vector<long long>(K + 5));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            cin >> A[i][j];
        }
    }
    vector<set<long long>> s(K + 5);
    vector<map<long long, int>> mn(K + 5), mx(K + 5);
    for (int j = 1; j <= K; j++) {
        for (int i = 1; i <= N; i++) {
            if (i > 1) A[i][j] |= A[i - 1][j];
            s[j].insert(A[i][j]);
            mx[j][A[i][j]] = i;
            if (mn[j][A[i][j]]) continue;
            mn[j][A[i][j]] = i;
        }
    }
    while (Q--) {
        cin >> M;
        int L = N;
        int R = 1;
        while (M--) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            if (o == '>') {
                if (s[r].upper_bound(c) == s[r].end()) {
                    R = N + 1;
                    continue;
                }
                R = max(R, mn[r][*s[r].upper_bound(c)]);
            }
            if (o == '<') {
                if (s[r].lower_bound(c) == s[r].begin()) {
                    L = 0;
                    continue;
                }
                L = min(L, mx[r][*(--s[r].lower_bound(c))]);
            }
        }
        cout << (L < R ? -1 : R) << "\n";
    }
}
