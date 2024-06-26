#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, A_ori, B_ori;

void solve() {
    cin >> A_ori >> B_ori;
    for (int sz = 3; sz <= 5; sz++) {
        int A = A_ori;
        int B = B_ori;
        vector<int> setA(sz+1);
        vector<int> setB(sz+1);
        for (int i = sz; i >= 1; i--) {
            if (i > sz-3) {
                setA[i] = 11;
                A -= 11;
                continue;
            }
            if (A < 0) continue;
            if (A > 10) {
                setA[i] = 10;
                A -= 10;
            }
            else {
                setA[i] = A;
                A = 0;
            }
        }
        for (int i = 1; i <= sz; i++) {
            if (i <= sz-3) {
                setB[i] = 11;
                B -= 11;
                continue;
            }
            if (B < 0) continue;
            if (B > 10) {
                setB[i] = 10;
                B -= 10;
            }
            else {
                setB[i] = B;
                B = 0;
            }
        }
        if (A != 0 || B != 0) continue;
        for (int i = 1; i <= sz; i++) {
            cout << setA[i] << " " << setB[i] << "\n";
        }
        return;
    }
    cout << -1 << " " << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
