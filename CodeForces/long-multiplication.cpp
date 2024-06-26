#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
string s, t;
int X[105];
int Y[105];

int cmp() {
    for (int i = 1; i <= N; i++) {
        if (X[i] > Y[i]) {
            return 1; // X is greater
        }
        if (Y[i] > X[i]) {
            return 2; // Y is greater
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> s >> t;
        N = (int)s.size();
        for (int i = 1; i <= N; i++) {
            X[i] = s[i-1]-'0';
        }
        for (int i = 1; i <= N; i++) {
            Y[i] = t[i-1]-'0';
        }
        for (int i = 1; i <= N; i++) {
            if (X[i] == Y[i]) continue;
            if (X[i] > Y[i]) {
                int D = X[i]-Y[i];
                Y[i] += D;
                for (int j = i; j > 0; j--) {
                    if (Y[j] > 9) {
                        Y[j-1]++;
                        Y[j] -= 10;
                    }
                }
                int flag2 = cmp();
                Y[i] -= D;
                for (int j = i; j > 0; j--) {
                    if (Y[j] < 0) {
                        Y[j-1]--;
                        Y[j] += 10;
                    }
                }
                if (flag2 == 1) {
                    swap(X[i], Y[i]);
                }
            }
            if (Y[i] > X[i]) {
                int D = Y[i]-X[i];
                X[i] += D;
                for (int j = i; j > 0; j--) {
                    if (X[j] > 9) {
                        X[j-1]++;
                        X[j] -= 10;
                    }
                }
                int flag2 = cmp();
                X[i] -= D;
                for (int j = i; j > 0; j--) {
                    if (X[j] < 0) {
                        X[j-1]--;
                        X[j] += 10;
                    }
                }
                if (flag2 == 2) {
                    swap(X[i], Y[i]);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            cout << X[i];
        } cout << "\n";
        for (int i = 1; i <= N; i++) {
            cout << Y[i];
        } cout << "\n";
    }
}
