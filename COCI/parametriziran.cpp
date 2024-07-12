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
            if (A[i][M-j-1] == '?') continue;
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
            for (int k = 0; k < M; k++) {
                if ((v1 & 1) && (v2 & 1)) {
                    v[k] = true;
                }
                v1 >>= 1;
                v2 >>= 1;
            }
            map<string, int> freq1, freq2;
            for (auto &k: B[i]) {
                string a = "";
                for (int l = 0; l < M; l++) {
                    if (!v[l]) continue;
                    a += A[k][M-l-1];
                }
                freq1[a]++;
            }
            for (auto &k: B[j]) {
                string b = "";
                for (int l = 0; l < M; l++) {
                    if (!v[l]) continue;
                    b += A[k][M-l-1];
                }
                freq2[b]++;
            }
            for (auto [x, y]: freq1) {
                int z = freq2[x];
                ans += z * y;
            }
        }
    }
    for (int i = 0; i < (1 << M); i++) {
        int v1 = i;
        vector<bool> v(M);
        for (int k = 0; k < M; k++) {
            if (v1 & 1) {
                v[k] = true;
            }
            v1 >>= 1;
        }
        map<string, int> freq;
        for (auto &k: B[i]) {
            string a = "";
            for (int l = 0; l < M; l++) {
                if (!v[l]) continue;
                a += A[k][M-l-1];
            }
            freq[a]++;
        }
        for (auto [x, y]: freq) {
            ans += y * (y - 1) / 2;
        }
    }
    cout << ans << "\n";
}
