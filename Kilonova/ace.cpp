#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1000;

int P, N, M;
int A[MAX_N + 5][MAX_N + 5];
bool seen[MAX_N + 5][MAX_N + 5];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.fi + p1.se < p2.fi + p2.se;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ace.in", "r", stdin);
    freopen("ace.out", "w", stdout);
    cin >> P >> N >> M;
    vector<pair<int, int>> v;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
            v.push_back({i - 1, j - 1});
        }
    }
    sort(v.begin(), v.end(), cmp);
    int total1 = 0;
    int total2 = 0;
    for (auto &[i, j]: v) {
        if (i == 0 && j == 0) continue;
        if (seen[N - i][M - j]) continue;
        double slope = 0.0;
        for (int k = 1; k * i < N && k * j < M; k++) {
            seen[N - k * i][M - k * j] = true;
            if ((double)A[N - k * i][M - k * j] > slope * (double)k) {
                slope = (double)A[N - k * i][M - k * j] / (double)k;
                if (i == 0 && j == 1) total1++;
                if (i == 1 && j == 0) total1++;
                total2++;
            }
        }
    }
    cout << (P == 1 ? total1 : total2) << "\n";
}
