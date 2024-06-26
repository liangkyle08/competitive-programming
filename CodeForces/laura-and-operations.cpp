#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;

bool check(int A, int B, int C) {
    C %= 2;
    if (C == 0) C = 2;
    B %= 2;
    if (B == 0) B = 2;
    return B == C;
}

void solve() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << check(A, min(B, C), max(B, C)) << " ";
    cout << check(B, min(A, C), max(A, C)) << " ";
    cout << check(C, min(A, B), max(A, B)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
