#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
int A[200001];
int B[200001];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N+M+1; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N+M+1; i++) {
        cin >> B[i];
    }
    vector<int> pos(N+M+2);
    int aCnt = 0;
    int bCnt = 0;
    vector<long long> ans(N+M+2);
    int bad = -1;
    for (int i = 1; i <= N+M; i++) {
        if (A[i] > B[i]) {
            if (aCnt == N) {
                pos[i] = 2;
                ans[N+M+1] += B[i];
                bCnt++;
                if (bad == -1) {
                    bad = i;
                }
            }
            else {
                pos[i] = 1;
                ans[N+M+1] += A[i];
                aCnt++;
            }
        }
        else {
            if (bCnt == M) {
                pos[i] = 1;
                ans[N+M+1] += A[i];
                aCnt++;
                if (bad == -1) {
                    bad = i;
                }
            }
            else {
                pos[i] = 2;
                ans[N+M+1] += B[i];
                bCnt++;
            }
        }
    }
    for (int i = 1; i <= N+M; i++) {
        ans[i] = ans[N+M+1];
        if (i < bad && pos[i] != pos[bad] && bad != -1) {
            if (pos[i] == 1) {
                ans[i] += (A[bad] - A[i]) + (B[N+M+1] - B[bad]);
            }
            else {
                ans[i] += (B[bad] - B[i]) + (A[N+M+1] - A[bad]);
            }
        }
        else {
            if (pos[i] == 1) {
                ans[i] += (A[N+M+1] - A[i]);
            }
            else {
                ans[i] += (B[N+M+1] - B[i]);
            }
        }
    }
    for (int i = 1; i <= N+M+1; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
