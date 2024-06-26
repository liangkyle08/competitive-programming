#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T;
string grid[3];

bool same(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    if (grid[A.fi][A.se] == '.') return false;
    if (grid[B.fi][B.se] == '.') return false;
    if (grid[C.fi][C.se] == '.') return false;
    return grid[A.fi][A.se] == grid[B.fi][B.se] && grid[B.fi][B.se] == grid[C.fi][C.se];
}

void solve() {
    for (auto &v: grid) {
        cin >> v;
    }
    // Rows
    for (int i = 0; i < 3; i++) {
        if (same({i, 0}, {i, 1}, {i, 2})) {
            cout << grid[i][0] << '\n';
            return;
        }
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (same({0, i}, {1, i}, {2, i})) {
            cout << grid[0][i] << '\n';
            return;
        }
    }
    // Diagonals
    if (same({0, 0}, {1, 1}, {2, 2})) {
        cout << grid[1][1] << '\n';
        return;
    }
    if (same({0, 2}, {1, 1}, {2, 0})) {
        cout << grid[1][1] << '\n';
        return;
    }
    // Draw
    cout << "DRAW\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
