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
int P[MAX_N + 5];
bool B[MAX_N + 5];

void solve() {
    cin >> N >> Q;
    vector<int> diff(N + 5);
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        diff[min(i, P[i])]++;
        diff[max(i, P[i])]--;
    }
    for (int i = 2; i <= N; i++) {
        diff[i] += diff[i - 1];
    }
    cin >> s;
    for (int i = 1; i <= N; i++) {
        B[i] = s[i - 1] == 'R';
    }
    set<int> st;
    for (int i = 1; i < N; i++) {
        if (!(!B[i] && B[i + 1] && diff[i])) continue;
        st.insert(i);
    }
    while (Q--) {
        int ind;
        cin >> ind;
        B[ind] = !B[ind];
        if (!B[ind - 1] && B[ind] && diff[ind - 1]) {
            st.insert(ind - 1);
        }
        else {
            st.erase(ind - 1);
        }
        if (!B[ind] && B[ind + 1] && diff[ind]) {
            st.insert(ind);
        }
        else {
            st.erase(ind);
        }
        cout << (!st.empty() ? "NO" : "YES") << "\n";
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
