#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

string s;
int N;
char A[1001][1001];
int ind = 0;

void check(int x1, int x2, int y1, int y2) {
    if (x1 == x2 && y1 == y2) {
        A[x1][y1] = s[ind];
        ind++;
        return;
    }
    if (isdigit(s[ind])) {
        ind++;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                A[i][j] = s[ind];
            }
        }
        ind++;
        return;
    }
    if (x2 - x1 >= 1 && y2 - y1 >= 1) {
        check(x1, (x1+x2)/2, y1, (y1+y2)/2);
        check((x1+x2)/2+1, x2, y1, (y1+y2)/2);
        check(x1, (x1+x2)/2, (y1+y2)/2+1, y2);
        check((x1+x2)/2+1, x2, (y1+y2)/2+1, y2);
        return;
    }
    if (x2 - x1 >= 1) {
        check(x1, (x1+x2)/2, y1, y2);
        check((x1+x2)/2+1, x2 , y1, y2);
        return;
    }
    if (y2 - y1 >= 1) {
        check(x1, x2, y1, (y1+y2)/2);
        check(x1, x2, (y1+y2)/2+1, y2);
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> s;
    N = 0;
    int cur = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            A[i][j] = '0';
        }
    }
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '*') continue;
        if (isdigit(s[i])) {
            cur = 10*cur+(s[i]-'0');
            continue;
        }
        if (i > 0 && cur > 0) {
            N += cur;
            cur = 0;
        }
        else {
            N++;
        }
    }
    N = (int)sqrt(N);
    check(1, 1, N, N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << A[i][j];
        } cout << "\n";
    }
}
