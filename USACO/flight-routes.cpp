#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int P[751][751];
int A[751][751];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    int ans = 0;
    for (int i = 1; i < N; i++) {
        string s;
        cin >> s;
        for (int j = i+1; j <= N; j++) {
            P[i][j] = (s[j-(i+1)]-'0');
            if (j == i+1) {
                A[i][j] = P[i][j];
                if (A[i][j]) ans++;
            }
        }
    }
    for (int x = 1; x < N-1; x++) {
        int i = 1;
        int j = x+2;
        while (i <= N && j <= N) {
            for (int k = i+1; k < j; k++) {
                A[i][j] += (A[i][k]*A[k][j]);
            }
            cout << i << " " << j << " " << A[i][j] << "\n";
            if ((A[i][j] % 2) != P[i][j]) {
                A[i][j]++;
                ans++;
            }
            i++;
            j++;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << A[i][j] << " ";
        } cout << "\n";
    }
    cout << ans << "\n";
}
