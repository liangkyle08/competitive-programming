#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e3;

int T, N, M;
int A[MAX_N + 5][MAX_N + 5];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            A[i][j] = s[j - 1] - '0';
        }
    }
    int ans = 0;
    for (int len = 1; len * 2 <= min(N, M); len++) {
        int i = len;
        int j = len;
        int cur = A[i][j];
        int val = 1543;
        while (j < M - len + 1) { // East
            j++;
            cur = (10 * cur + A[i][j]) % 10000;
            ans += (cur == val);
        }
        while (i < N - len + 1) { // South
            i++;
            cur = (10 * cur + A[i][j]) % 10000;
            ans += (cur == val);
        }
        while (j > len) { // West
            j--;
            cur = (10 * cur + A[i][j]) % 10000;
            ans += (cur == val);
        }
        while (i > len) { // North
            i--;
            cur = (10 * cur + A[i][j]) % 10000;
            ans += (cur == val);
        }
        // Loop back again
        int cnt = 2;
        while (j < M - len + 1 && cnt > 0) { // East
            j++;
            cnt--;
            cur = (10 * cur + A[i][j]) % 10000;
            ans += (cur == val);
        }
        while (i < N - len + 1 && cnt > 0) { // South
            i++;
            cnt--;
            cur = (10 * cur + A[i][j]) % 10000;
            ans += (cur == val);
        }
        while (j > len && cnt > 0) { // West
            j--;
            cnt--;
            cur = (10 * cur + A[i][j]) % 10000;
            ans += (cur == val);
        }
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
