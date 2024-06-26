#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
string S, P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> S >> P;
        N = (int)S.size();
        M = (int)P.size();
        vector<int> left1(M+1, -1), right1(M+1, -1);
        vector<int> left2(M+1, -1), right2(M+1, -1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i+j >= N) break;
                if (S[i+j] == P[j]) {
                    if (left1[j+1] == -1) left1[j+1] = i;
                    left2[j+1] = i;
                    continue;
                }
                break;
            }
        }
        for (int i = N-1; i >= 0; i--) {
            for (int j = M-1; j >= 0; j--) {
                if (i-(M-j-1) < 0) break;
                if (S[i-(M-j-1)] == P[j]) {
                    if (right1[M-j] == -1) right1[M-j] = i-(M-j-1);
                    right2[M-j] = i-(M-j-1);
                    continue;
                }
                break;
            }
        }
        bool flag = false;
        for (int i = 1; i < M; i++) {
            if (left1[i] >= 0 and right1[M-i] >= 0) {
                pair<int, int> A = {left1[i], left1[i]+i-1};
                pair<int, int> B = {right1[M-i], right1[M-i]+M-i-1};
                if (A.fi > B.fi) swap(A, B);
                if (A.se < B.fi && A.fi != B.fi) {
                    flag = true;
                    cout << left1[i] << " " << i << " " << right1[M-i] << " " << M-i << "\n";
                    break;
                }
            }
            if (left2[i] >= 0 and right2[M-i] >= 0) {
                pair<int, int> A = {left2[i], left2[i]+i-1};
                pair<int, int> B = {right2[M-i], right2[M-i]+M-i-1};
                if (A.fi > B.fi) swap(A, B);
                if (A.se < B.fi && A.fi != B.fi) {
                    flag = true;
                    cout << left2[i] << " " << i << " " << right2[M-i] << " " << M-i << "\n";
                    break;
                }
            }
        }
        if (!flag) cout << "IMPOSSIBLE\n";
    }
}