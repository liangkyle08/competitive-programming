#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M, K;
int A[505][505];
int B[505][505];
int pSum[505][505];

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
            pSum[i][j] = 0;
            B[i][j] = 0;
        }
    }
    long long diff = 0;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            B[i][j] = s[j-1]-'0';
            if (B[i][j] == 0) diff += A[i][j];
            if (B[i][j] == 1) diff -= A[i][j];
            pSum[i][j] = B[i][j]+pSum[i-1][j]+pSum[i][j-1]-pSum[i-1][j-1];
            //cout << pSum[i][j] << " ";
        } //cout << "\n";
    }
    diff = abs(diff);
    set<long long> div;
    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            int cur = pSum[i][j]-pSum[i-K][j]-pSum[i][j-K]+pSum[i-K][j-K];
            if (cur == 0) {
                div.insert(K*K);
                continue;
            }
            div.insert(abs(cur));
        }
    }
    for (auto &v: div) {
        if (diff % v == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
