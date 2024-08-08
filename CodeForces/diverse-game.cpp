#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 10;
const int MAX_M = 10;

int T, N, M;
int A[MAX_N + 5][MAX_M + 5];
int B[MAX_N + 5][MAX_M + 5];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        int maxVal = N * M;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++)  {
                cin >> A[i][j];
                B[i][j] = (A[i][j] == maxVal ? 1 : A[i][j] + 1);
            }
        }
        bool flag = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++)  {
                flag |= (A[i][j] == B[i][j]);
            }
        }
        if (flag) {
            cout << -1 << "\n";
        }
        else {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++)  {
                    cout << B[i][j] << " ";
                } cout << "\n";
            }
        }
    }
}
