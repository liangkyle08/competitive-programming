#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;
const int MAX_K = 2e5;

int N, K;
long long C[MAX_N+5];
pair<int, int> Q[MAX_K+5];
int lastQuery[MAX_N+5];
long long sum[MAX_N+5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }
    for (int i = 1; i <= K; i++) {
        cin >> Q[i].fi >> Q[i].se;
        Q[i].fi++;
        lastQuery[Q[i].fi] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= K; i++) {
        int &t = Q[i].fi;
        int &v = Q[i].se;
        if (sum[t] + v > C[t]) {
            ans += C[t] - sum[t];
            sum[t] = 0;
        }
        sum[t] += v;
        if (i == lastQuery[t]) {
            ans += C[t] - sum[t];
            sum[t] = 0;
        }
    }
    cout << ans << "\n";
}
