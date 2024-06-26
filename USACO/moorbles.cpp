#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        vector<int> odd(M+1, (1<<30)), even(M+1, (1<<30));
        for (int i = 1; i <= M; i++) {
            set<int> oddSet, evenSet;
            for (int j = 1; j <= K; j++) {
                int v;
                cin >> v;
                if (v % 2 == 1) {
                    odd[i] = min(odd[i], v);
                    even[i] = min(even[i], -v);
                }
                else {
                    odd[i] = min(odd[i], -v);
                    even[i] = min(even[i], v);
                }
            }
        }
        vector<int> psum(M+5);
        for (int i = M; i >= 1; i--) {
            psum[i] = min(0, max(even[i], odd[i])+psum[i+1]);
        }
        if (N+psum[1] <= 0) {
            cout << -1 << "\n";
            continue;
        }
        vector<bool> ans(M+1);
        for (int i = 1; i <= M; i++) {
            if (N+even[i]+psum[i+1] <= 0) {
                ans[i] = true;
                N += odd[i];
            }
            else {
                N += even[i];
            }
        }
        for (int i = 1; i <= M; i++) {
            cout << ((ans[i]) ? "Odd" : "Even");
            if (i < M) cout << " ";
        } cout << "\n";
    }
}