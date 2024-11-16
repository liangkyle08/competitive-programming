#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1000;

int N, M;
int A[MAX_N + 5][MAX_N + 5];
int B[2][MAX_N + 5][MAX_N + 5];
int P[MAX_N + 5][MAX_N + 5];
int H[MAX_N + 5][MAX_N + 5];

int solve(bool T) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            H[i][j] = 0;
            if (A[i][j] == B[T][i][j]) {
                H[i][j] = H[i - 1][j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        vector<int> L(M + 1);
        vector<int> R(M + 1);
        stack<int> s;
        for (int j = 1; j <= M; j++) {
            while (!s.empty() && H[i][s.top()] >= H[i][j]) {
                s.pop();
            }
            L[j] = (!s.empty() ? s.top() : 0);
            s.push(j);
        }
        while (!s.empty()) s.pop();
        for (int j = M; j >= 1; j--) {
            while (!s.empty() && H[i][s.top()] >= H[i][j]) {
                s.pop();
            }
            R[j] = (!s.empty() ? s.top() : M + 1);
            s.push(j);
        }
        for (int j = 1; j <= M; j++) {
            ans = max(ans, H[i][j] * (R[j] - L[j] - 1));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fadema.in", "r", stdin);
    freopen("fadema.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
            B[0][i][j] = (i + j) % 2;
            B[1][i][j] = (i + j + 1) % 2;
        }
    }
    cout << max(solve(0), solve(1)) << "\n";
}
