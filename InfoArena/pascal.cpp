#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int R, D;
int cntFactors[3][5000001]; // 2, 3, 5
int diff[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pascal.in", "r", stdin);
    freopen("pascal.out", "w", stdout);
    cin >> R >> D;
    for (int i = 2; i <= R; i++) {
        for (int j = 0; j < 3; j++) {
            cntFactors[j][i] = cntFactors[j][i-1];
        }
        int j = i;
        while (j % 2 == 0) {
            cntFactors[0][i]++;
            j /= 2;
        }
        while (j % 3 == 0) {
            cntFactors[1][i]++;
            j /= 3;
        }
        while (j % 5 == 0) {
            cntFactors[2][i]++;
            j /= 5;
        }
    }
    while (D % 2 == 0) {
        diff[0]++;
        D /= 2;
    }
    while (D % 3 == 0) {
        diff[1]++;
        D /= 3;
    }
    while (D % 5 == 0) {
        diff[2]++;
        D /= 2;
    }
    int ans = 0;
    for (int i = 0; i <= R; i++) {
        bool flag = true;
        for (int j = 0; j < 3; j++) {
            if (cntFactors[j][R]-(cntFactors[j][i]+cntFactors[j][R-i]) < diff[j]) {
                flag = false;
            }
        }
        ans += flag;
    }
    cout << ans << "\n";
}
