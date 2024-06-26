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
    for (auto v: c) {
        for (int i = 0; i+v <= X; i++) {
            if (DP[i] == 0) continue;
            DP[i+v] = (DP[i+v]+DP[i]) % MOD;
        }
    }
    cout << DP[X] << "\n";
}
