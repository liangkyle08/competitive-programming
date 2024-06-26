#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> s;
    int squareCnt = 0;
    int primeCnt = 0;
    set<int> squares = {0, 1, 4, 9};
    set<int> primes = {2, 3, 5, 7};
    for (int i = 0; i < N; i++) {
        int v = (s[i]-'0');
        squareCnt += (squares.find(v) != squares.end());
        primeCnt += (primes.find(v) != primes.end());
    }
    if (squareCnt == primeCnt) {
        cout << "Equal\n";
    }
    if (squareCnt < primeCnt) {
        cout << "Prime\n";
    }
    if (squareCnt > primeCnt) {
        cout << "Square\n";
    }
}
