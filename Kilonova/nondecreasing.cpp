#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
string s;
int arr[500001];
int DP[27][500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nondecreasing.in", "r", stdin);
    freopen("nondecreasing.out", "w", stdout);
    cin >> s;
    N = (int)s.size();
    for (int i = 1; i <= N; i++) {
        arr[i] = s[i-1]-'a'+1;
    }
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= N; j++) {
            DP[i][j] = (1<<30);
        }
    }
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= 26; i++) {
            if (DP[i][j] > DP[i][j-1]+(arr[j]+i)*(arr[j] != i)) {
                DP[i][j] = DP[i][j-1]+(arr[j]+i)*(arr[j] != i);
            }
        }
        for (int i = 2; i <= 26; i++) {
            if (DP[i][j] > DP[i-1][j]) {
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    int ans = (1<<30);
    for (int i = 1; i <= 26; i++) {
        ans = min(ans, DP[i][N]);
    }
    cout << ans << "\n";
}
