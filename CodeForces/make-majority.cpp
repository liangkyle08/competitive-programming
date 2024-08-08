#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
string s;
int A[MAX_N+5];

void solve() {
    cin >> N >> s;
    vector<int> B;
    for (int i = 1; i <= N; i++) {
        A[i] = s[i - 1] - '0';
        if (!B.empty() && B.back() == A[i] && !A[i]) continue;
        B.push_back(A[i]);
    }
    array<int, 2> cnt = {0, 0};
    bool flag = false;
    int mark = -1;
    for (int i = 0, M = (int)B.size(); i < M; i++) {
        cnt[B[i]]++;
    }
    cout << (cnt[1] > cnt[0] ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
