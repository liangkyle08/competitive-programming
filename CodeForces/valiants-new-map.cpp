#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, N, M;
vector<vector<int>> A;
vector<vector<int>> P;

bool check(int L) {
    P.clear();
    P.resize(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + (A[i][j] < L);
        }
    }
    for (int i = 1; i <= N - L + 1; i++) {
        for (int j = 1; j <= M - L + 1; j++) {
            int cur = P[i + L - 1][j + L - 1] - P[i + L - 1][j - 1] - P[i - 1][j + L - 1] + P[i - 1][j - 1];
            if (cur > 0) continue;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> N >> M;
    A.clear();
    A.resize(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }
    int low = 1;
    int high = min(N, M);
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
