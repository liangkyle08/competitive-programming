#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, X;

void solve() {
    cin >> N >> X;
    vector<int> P(N+1);
    int ind = 0;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        if (P[i] == X) ind = i;
    }
    int low = 1;
    int high = N+1;
    while (high - low != 1) {
        int mid = (low + high) / 2;
        if (P[mid] <= X) {
            low = mid;
        }
        else {
            high = mid;
        }

    }
    cout << 1 << "\n";
    cout << ind << " " << low << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
