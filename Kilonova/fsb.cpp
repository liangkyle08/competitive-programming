#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

long long K, N, D, T;
string s;
bool A[2001];
int B[10001][10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("fsb.in", "r", stdin);
    // freopen("fsb.out", "w", stdout);
    cin >> K >> N >> D >> s;
    for (int i = 0; i < K; i++) {
        A[i] = s[i] == 'b';
    }
    T = K*N/D;
    vector<long long> prev(N+1), cur(N+1);
    long long ans = 0;
    long long cnc = 0;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < D; j++) {
            cur[j] = 0;
            long long ind = (i*D+j) % K;
            if (!A[ind]) {
                prev[ind] = A[ind];
                continue;
            }
            bool leftBool = (j > 0 && A[(ind + K - 1) % K]) ? cur[j-1] : 0;
            bool topBool = prev[j];
            if (!leftBool && !topBool) {
                ans++;
                cnc++;
                prev[j] = cnc;
                cur[j] = cnc;
                continue;
            }
            if (leftBool && topBool) {
                if (leftBool != topBool) {
                    ans--;
                }
            }
            prev[j] = max(leftBool, topBool);
            cur[j] = max(leftBool, topBool);
            B[i][j] = cur[j];
        }
    }
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < D; j++) {
            cout << B[i][j] << " ";
        } cout << "\n";
    }
    cout << ans << "\n";
}
