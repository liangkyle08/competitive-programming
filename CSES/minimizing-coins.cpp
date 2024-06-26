// CSES Problem Set
// Minimizing Coins
// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

int N, X;

int main() {
    cin >> N >> X;
    vector<int> arr(N);
    vector<int> DP(1000001, INT_MAX);
    for (auto &v: arr) {
        cin >> v;
        DP[v] = 1;
    }
    for (int i = 1; i <= X; i++) {
        if (DP[i] != INT_MAX) {
            for (auto v: arr) {
                if (i + v <= X) {
                    DP[i + v] = min(DP[i + v], DP[i] + 1);
                }
            }
        }
    }
    if (DP[X] == INT_MAX) DP[X] = -1;
    cout << DP[X] << "\n";
}
