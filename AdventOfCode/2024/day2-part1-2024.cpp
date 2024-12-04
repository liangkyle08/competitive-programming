#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1000;

int N;
int A[MAX_N + 5][MAX_N + 5];
int len[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    N = 1000;
    for (int i = 1; i <= N; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        len[i] = 1;
        while (ss >> A[i][len[i]]) len[i]++;
        len[i]--;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        bool dec = false;
        bool inc = false;
        int mx = -INF;
        int mn = INF;
        for (int j = 1; j < len[i]; j++) {
            dec |= A[i][j + 1] < A[i][j];
            inc |= A[i][j + 1] > A[i][j];
            mx = max(mx, abs(A[i][j + 1] - A[i][j]));
            mn = min(mn, abs(A[i][j + 1] - A[i][j]));
        }
        ans += (dec ^ inc) && (mx <= 3) && (mn >= 1);
    }
    cout << ans << "\n";
}
