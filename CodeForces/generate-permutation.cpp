#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, N;

void solve() {
    cin >> N;
    if (N % 2 == 0) {
        cout << -1 << "\n";
        return;
    }
    vector<int> ans(N + 1);
    bool parity = true;
    int leftPtr = 1;
    int rightPtr = N;
    for (int i = 1; i <= N; i++) {
        if (parity) {
            ans[leftPtr] = i;
            leftPtr++;
        }
        else {
            ans[rightPtr] = i;
            rightPtr--;
        }
        parity = !parity;
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
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
