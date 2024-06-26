#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        int ans = (1<<30);
        int cur = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i] == A[1]) {
                cur++;
            }
            if (i == N || A[i+1] != A[1]) {
                ans = min(cur, ans);
                cur = 0;
            }
        }
        cout << (ans == N ? -1 : ans) << "\n";
    }
}
