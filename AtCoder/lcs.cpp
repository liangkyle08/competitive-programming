#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int N, M;
string s, t;
int DP[3001][3001];
int sz[3001][3001];

void getStr(int x, int y) {
    if (x == 0 && y == 0) {
        return;
    }
    if (DP[x][y] == 1) {
        getStr(x-1, y);
    }
    if (DP[x][y] == 2) {
        getStr(x, y-1);
    }
    if (DP[x][y] == 3) {
        getStr(x-1, y-1);
        cout << s[x-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    N = (int)s.size();
    M = (int)t.size();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (sz[i-1][j] >= sz[i][j-1]) {
                DP[i][j] = 1;
                sz[i][j] = sz[i-1][j];
            }
            if (sz[i][j-1] >= sz[i-1][j]) {
                DP[i][j] = 2;
                sz[i][j] = sz[i][j-1];
            }
            if (s[i-1] == t[j-1] && sz[i-1][j-1] >= sz[i][j]) {
                DP[i][j] = 3;
                sz[i][j] = sz[i-1][j-1]+1;
            }
        }
    }
    getStr(N, M);
    cout << "\n";
}