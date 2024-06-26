#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int N, X;
int DP[1000001];

int main() {
    cin >> N >> X;
    vector<int> c(N);
    for (auto &v: c) cin >> v;
    DP[0] = 1;
    for (int i = 0; i <= X; i++) {
        if (DP[i] == 0) continue;
        for (auto v: c) {
            if (i+v > X) continue;
            DP[i+v] = (DP[i+v]+DP[i]) % MOD;
        }
    }
    cout << DP[X] << "\n";
}
