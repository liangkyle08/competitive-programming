#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;
const int MAX_Q = 1e5;

int T, N, Q;
int A[MAX_N + 5];

void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    set<int> pos;
    for (int i = 1; i <= N; i++) {
        if (A[i] != 1) continue;
        pos.insert(i - 1);
    }
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int s;
            cin >> s;
            int cnt = (int)pos.size();
            if ((s - cnt) % 2 == 1) {
                if (cnt == 0) {
                    cout << "NO\n";
                    continue;
                }
                int leftSum = 2 * (*pos.rbegin()) - (cnt - 1);
                int rightSum = 2 * (N - *pos.begin() - 1) - (cnt - 1);
                cout << (s <= max(leftSum, rightSum) ? "YES" : "NO") << "\n";
            }
            else {
                cout << (s <= 2 * N - cnt ? "YES" : "NO") << "\n";
            }
        }
        else {
            int i, v;
            cin >> i >> v;
            pos.erase(i - 1);
            A[i] = v;
            if (A[i] != 1) continue;
            pos.insert(i - 1);
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
