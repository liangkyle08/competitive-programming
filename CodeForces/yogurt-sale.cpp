#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> A >> B;
        if (B < 2*A) {
            cout << (N / 2)*B+(N % 2)*A << "\n";
        }
        else {
            cout << N*A << "\n";
        }
    }
}
