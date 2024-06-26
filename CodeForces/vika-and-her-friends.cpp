#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M, K;

void solve() {
    cin >> N >> M >> K;
    int x1, y1;
    cin >> x1 >> y1;
    vector<bool> maxDist(4); // Up, Down, Left, Right
    for (int i = 1; i <= K; i++) {
        int x2, y2;
        cin >> x2 >> y2;
        int a = abs(x2-x1);
        int b = abs(y2-y1);
        if (a < b) {
            if (y2 > y1) {
                maxDist[0] = true;
            }
            if (y2 < y1) {
                maxDist[1] = true;
            }
            if (y2 == y1) {
                maxDist[0] = true;
                maxDist[1] = true;
            }
        }
        if (b < a) {
            if (x2 > x1) {
                maxDist[3] = true;
            }
            if (x2 < x1) {
                maxDist[2] = true;
            }
            if (x2 == x1) {
                maxDist[3] = true;
                maxDist[2] = true;
            }
        }
    }
    bool pos = false;
    for (auto v: maxDist) {
        if (!v) pos = true;
    }
    if (pos) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
