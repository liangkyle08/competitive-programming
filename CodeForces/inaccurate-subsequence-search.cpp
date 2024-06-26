#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M, K;
int A[200001];
int B[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        map<int, int> BFreq;
        for (int i = 1; i <= M; i++) {
            cin >> B[i];
            BFreq[B[i]]++;
        }
        map<int, int> CFreq;
        int k = 0;
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            CFreq[A[i]]++;
            if (CFreq[A[i]] <= BFreq[A[i]]) k++;
            if (i > M) {
                CFreq[A[i-M]]--;
                if (CFreq[A[i-M]] < BFreq[A[i-M]]) k--;
            }
            if (i >= M) ans += (k >= K);
        }
        cout << ans << "\n";
    }
}
