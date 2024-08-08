#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
long long X;
int A[MAX_N + 5];
long long P[MAX_N + 5];
long long DP[MAX_N + 5];

long long binSearch(int i) {
    int low = i;
    int high = N + 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (P[mid] - P[i - 1] > X) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> X;
        memset(A, 0, sizeof(A));
        memset(P, 0, sizeof(P));
        memset(DP, 0, sizeof(DP));
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            P[i] = A[i] + P[i - 1];
        }
        for (int i = N; i >= 1; i--) {
            int j = binSearch(i);
            if (j == N + 1) {
                DP[i] = N - i + 1;
            }
            else {
                DP[i] = DP[j + 1] + j - i;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += DP[i];
        }
        cout << ans << "\n";
    }
}
