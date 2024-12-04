#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
long long K;
long long L[MAX_N + 5];
long long R[MAX_N + 5];
long long len[MAX_N + 5];

bool cmp(int A, int B) {
    double ratioA = (double)len[A] / (double)L[A];
    double ratioB = (double)len[B] / (double)L[B];
    if (ratioA == ratioB) return len[A] < len[B];
    return ratioA > ratioB;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> R[i];
    }
    vector<int> ind(N + 1);
    for (int i = 1; i <= N; i++) {
        len[i] = R[i] - L[i] + 1;
        ind[i] = i;
    }
    sort(ind.begin() + 1, ind.end(), cmp);
    vector<int> key(N + 1);
    key[1] = 1;
    for (int i = 2; i <= N; i++) {
        double curRatio = (double)len[i] / (double)L[i];

    }
    long long maxDist = 0;
    for (int i = 1; i <= N; i++) {
        if (K <= len[ind[i]]) {
            maxDist = max(maxDist, L[ind[i]] + K - 1);
            maxDist += 2 * i;
            K = 0;
            break;
        }
        maxDist = max(maxDist, R[ind[i]]);
        K -= len[ind[i]];
    }
    cout << (K == 0 ? maxDist : -1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
