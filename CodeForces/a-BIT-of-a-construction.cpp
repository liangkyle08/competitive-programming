#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
int pow2[32];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    pow2[0] = 1;
    for (int i = 1; i < 32; i++) {
        pow2[i] = 2*pow2[i-1];
    }
    while (T--) {
        cin >> N >> K;
        if (N == 1) {
            cout << K << "\n";
            continue;
        }
        int A = 0;
        int B = 0;
        for (int i = 0; i < 32; i++) {
            if (pow2[i]-1 > K) break;
            int cnt = 0;
            for (int j = 0; j < 32; j++) {
                cnt += ((A & (1<<j)) | (B & (1<<j))) ? 1 : 0;

            }
            int cnt2 = 0;
            for (int j = 0; j < 32; j++) {
                cnt2 += (((pow2[i]-1) & (1<<j)) | ((K-pow2[i]+1) & (1<<j))) ? 1 : 0;
            }
            if (cnt2 > cnt) {
                A = pow2[i]-1;
                B = K-pow2[i]+1;
            }
        }
        cout << A << " " << B << " ";
        for (int i = 2; i < N; i++) {
            cout << 0 << " ";
        } cout << "\n";
    }
}
