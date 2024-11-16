#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N, Q;
string s;
int A[MAX_N + 5];

bool check(int i) {
    return A[i] && A[i + 1] && !A[i + 2] && !A[i + 3];
}

void solve() {
    cin >> s;
    N = (int)s.size();
    for (int i = 1; i <= N; i++) {
        A[i] = s[i - 1] == '1';
    }
    set<int> st;
    for (int i = 1; i <= N - 3; i++) {
        if (!check(i)) continue;
        st.insert(i);
    }
    cin >> Q;
    while (Q--) {
        int ind, val;
        cin >> ind >> val;
        if (A[ind] == val) {
            cout << (!st.empty() ? "YES" : "NO") << "\n";
            continue;
        }
        for (int j = max(1, ind - 3); j <= min(N - 3, ind); j++) {
            if (st.find(j) != st.end()) st.erase(j);
        }
        A[ind] = val;
        for (int j = max(1, ind - 3); j <= min(N - 3, ind); j++) {
            if (!check(j)) continue;
            st.insert(j);
        }
        cout << (!st.empty() ? "YES" : "NO") << "\n";
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
