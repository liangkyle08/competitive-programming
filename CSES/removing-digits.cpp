#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int N;
int DP[1000001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        DP[i] = (1 << 30);
    }
    for (int i = N; i >= 0; i--) {
        string s = to_string(i);
        for (auto c: s) {
            int v = c-'0';
            if (i-v >= 0) {
                DP[i-v] = min(DP[i-v], DP[i]+1);
            }
        }
    }
    cout << DP[0] << "\n";
}
