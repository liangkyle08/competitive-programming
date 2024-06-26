#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

long long N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                for (int d = 0; d < 10; d++) {
                    if (a+b+c+d == a*b*c*d) {
                        cout << a << b << c << d << "\n";
                    }
                }
            }
        }
    }
    //cin >> N;
    //cout << (N-1)+3*(N-1)*(N-2) << "\n";
}
