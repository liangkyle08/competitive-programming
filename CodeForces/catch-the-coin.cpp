#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, X, Y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        int Y2 = Y - (abs(X) - 1);

        if (Y2 < -abs(X)) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}
