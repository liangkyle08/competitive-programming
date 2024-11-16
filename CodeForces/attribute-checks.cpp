#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e6;
const int MAX_M = 5000;

int N, M;
int A[MAX_N + 5];
int diff[MAX_M + 5];
int DP[MAX_M + 5];

void addSegment(int L, int R) {
    if (L > R) return;
    diff[L]++;
    diff[R + 1]--;
}

void pushAll() {
    int sum = 0;
    for (int i = 0; i <= M; i++) {
        sum += diff[i];
        DP[i] += sum;
    }
    for (int i = 0; i <= M + 1; i++) {
        diff[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= M; i++) {
        DP[i] = -INF;
    }
    int cntPoints = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] == 0) {
            pushAll();
            for (int j = M; j >= 1; j--) {
                DP[j] = max(DP[j], DP[j - 1]);
            }
            cntPoints++;
            continue;
        }
        int L = 0;
        int R = 0;
        if (A[i] > 0) {
            L = min(A[i], M + 1);
            R = M;
        }
        else {
            L = 0;
            R = max(-1, cntPoints + A[i]);
        }
        addSegment(L, R);
    }
    pushAll();
    int ans = 0;
    for (int i = 0; i <= M; i++) {
        ans = max(ans, DP[i]);
    }
    cout << ans << "\n";
}
