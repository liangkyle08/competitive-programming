#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
int B[MAX_N + 5];

void solve() {
    cin >> N;
    vector<bool> seen(N + 1);
    bool flag = false;
    for (int i = 1; i <= N / 2; i++) {
        cin >> B[i];
        if (seen[B[i]]) flag = true;
        seen[B[i]] = true;
    }
    set<int> s;
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        s.insert(i);
    }
    if (flag) {
        cout << -1 << "\n";
        return;
    }
    vector<int> A;
    for (int i = N / 2; i >= 1; i--) {
        if (s.upper_bound(B[i]) == s.begin()) {
            flag = true;
            break;
        }
        A.push_back(B[i]);
        A.push_back(*(--s.upper_bound(B[i])));
        s.erase(--s.upper_bound(B[i]));
    }
    if (flag) {
        cout << -1 << "\n";
        return;
    }
    reverse(A.begin(), A.end());
    for (auto &v: A) {
        cout << v << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
