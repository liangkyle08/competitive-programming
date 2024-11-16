#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, N, K;

bool solve() {
    cin >> N >> K;
    if (N % 2 == 0) {
        if ((K / 2) % 2 == 0) return true;
    }
    else {
        if (((K + 1) / 2) % 2 == 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}
