#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[200001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A+1, A+N+1);
    vector<int> B;
    for (int i = 1; i <= N; i++) {
        if (!B.empty() && B.back() == A[i]) continue;
        B.push_back(A[i]);
    }
    int ans = -1;
    int cur = 1;
    int sub = 0;
    for (int i = 0; i < (int)B.size(); i++) {
        if (B[i]-sub >= 2) {
            ans = cur;
            break;
        }
        if (B[i]-sub == 1) {
            cur ^= 1;
        }
        sub = B[i];
    }
    if (ans == -1) {
        ans = (cur ^ 1);
    }
    cout << (ans ? "Alice" : "Bob") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
