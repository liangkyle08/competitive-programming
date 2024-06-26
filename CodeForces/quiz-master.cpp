#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int MAX_M = 1e5;
vector<int> factors[MAX_M+5];


int T, N, M;
int A[100005];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A+1, A+N+1);
    int L = 0;
    int R = 0;
    vector<int> freq(M+5);
    int cnt = 0;
    int ans = (1<<30);
    while (L < N && R < N) {
        if (cnt == M) {
            L++;
            ans = min(ans, A[R]-A[L]);
            for (auto &v: factors[A[L]]) {
                if (v > M) continue;
                freq[v]--;
                if (freq[v] == 0) {
                    cnt--;
                }
            }
        }
        else {
            R++;
            for (auto &v: factors[A[R]]) {
                if (v > M) continue;
                freq[v]++;
                if (freq[v] == 1) {
                    cnt++;
                }
            }
        }
    }
    while (cnt == M && L < N) {
        L++;
        ans = min(ans, A[R]-A[L]);
        for (auto &v: factors[A[L]]) {
            if (v > M) continue;
            freq[v]--;
            if (freq[v] == 0) {
                cnt--;
            }
        }
    }
    cout << ((ans) == (1<<30) ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= MAX_M; i++) {
        for (int j = i; j <= MAX_M; j += i) {
            factors[j].push_back(i);
        }
    }
    cin >> T;
    while (T--) {
        solve();
    }
}
