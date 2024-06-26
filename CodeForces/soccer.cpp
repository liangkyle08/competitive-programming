#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, A, B, C, D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> A >> B >> C >> D;
        if (A < B && C > D) {
            cout << "NO\n";
            continue;
        }
        if (A > B && C < D) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}
