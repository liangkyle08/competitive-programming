#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
string A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> A >> B;
        cout << B.substr(0, 1)+A.substr(1, 2) << " " << A.substr(0, 1)+B.substr(1, 2) << "\n";
    }
}
