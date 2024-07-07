#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);

const int MAX_N = 2e5;

int N, C;
int A[MAX_N+1];
int B[MAX_N+1];
long long DP[2][MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> C;
    for (int i = 1; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i < N; i++) {
        cin >> B[i];
    }
    memset(DP, INF, sizeof(DP));
    DP[0][1] = 0;
    DP[1][1] = C;
    for (int i = 2; i <= N; i++) {
        DP[0][i] = min(DP[0][i-1]+A[i-1], DP[1][i-1]+A[i-1]);
        DP[1][i] = min(DP[1][i-1]+B[i-1], DP[0][i-1]+B[i-1]+C);
    }
    for (int i = 1; i <= N; i++) {
        cout << min(DP[0][i], DP[1][i]) << " ";
    } cout << "\n";
}
