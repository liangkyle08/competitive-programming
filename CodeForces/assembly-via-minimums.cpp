#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
vector<int> B;

void solve() {
    cin >> N;
    int M = N*(N-1)/2;
    B.clear();
    B.resize(M+1);
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
    }
    sort(B.begin()+1, B.end());
    vector<int> ans(N+1);
    int j = 1;
    for (int i = N-1; i >= 1; i--) {

        ans[N-i] = B[j];
        j += i;
    }
    ans[N] = 1e9;
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
