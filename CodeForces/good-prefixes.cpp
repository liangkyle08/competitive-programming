#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        long long sum = 0LL;
        long long mx = 0LL;
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i] >= mx) {
                sum += mx;
                mx = A[i];
            }
            else {
                sum += A[i];
            }
            if (mx == sum) ans++;
        }
        cout << ans << "\n";
    }
}
