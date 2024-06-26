#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

string s;
int N, Q;
int C[200001];
int O[200001];
int W[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> s;
    N = (int)s.size();
    for (int i = 1; i <= N; i++) {
        C[i] = C[i-1];
        O[i] = O[i-1];
        W[i] = W[i-1];
        if (s[i-1] == 'C') C[i]++;
        if (s[i-1] == 'O') O[i]++;
        if (s[i-1] == 'W') W[i]++;
    }
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        int cQuery = C[r]-C[l-1];
        int oQuery = O[r]-O[l-1];
        int wQuery = W[r]-W[l-1];
        if (((cQuery+oQuery) % 2 == 1)
            && ((oQuery+wQuery) % 2 == 0)) {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    } cout << "\n";
}
