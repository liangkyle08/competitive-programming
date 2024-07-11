#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 5e4;

int N, M;
string A[MAX_N+5];
vector<int> B[63];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        int val = 0;
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '?') continue;
            val += (1<<j);
        }
        B[val].push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < (1 << M); i++) {
        for (int j = i+1; j < (1 << M); j++) {
            int v1 = i;
            int v2 = j;
            vector<bool> v(M);
            int sz = 0;
            for (int k = 0; k < M; k++) {
                if ((v1 & 1) && (v2 & 1)) {
                    v[k] = true;
                    sz++;
                }
                v1 >>= 1;
                v2 >>= 1;
            }
            map<string, int> freq;
            for (auto &k: B[i]) {
                string a = "";
                for (int l = M-1; l >= 0; l--) {
                    if (!v[l]) continue;
                    a += A[k][l];
                }
                freq[a]++;
            }
            for (auto &k: B[j]) {
                string b = "";
                for (int l = M-1; l >= 0; l--) {
                    if (!v[l]) continue;
                    b += A[k][l];
                }
                freq[b]++;
            }
            if (!freq.empty()) {
                cout << i << " " << j << "\n";
                for (int l = M-1; l >= 0; l--) {
                    cout << v[l];
                } cout << "\n";
            }
            for (auto [x, y]: freq) {
                cout << x << " " << y << "\n";
                ans += y * (y - 1) / 2;
            } //cout << "\n";
        }
    }
    cout << ans << "\n";
}
