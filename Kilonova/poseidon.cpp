#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e6;

int N, Q, L, R;
string s;
int leftSum[MAX_N + 5];
int midSum[MAX_N + 5];
int rightSum[MAX_N + 5];
int leftInd[MAX_N + 5];
int midInd[MAX_N + 5];
int rightInd[MAX_N + 5];

void solve() {
    cin >> L >> R;
    int low = 0;
    int high = R - L + 1;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        int ind = L;
        if (ind != INF) ind = leftInd[leftSum[ind - 1] + mid];
        if (ind != INF) ind = midInd[midSum[ind - 1] + mid];
        if (ind != INF) ind = rightInd[rightSum[ind - 1] + mid];
        if (ind <= R) {
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
    cin >> N >> Q >> s;
    for (int i = 1; i <= N; i++) {
        leftSum[i] = leftSum[i - 1] + (s[i - 1] == '\\');
        midSum[i] = midSum[i - 1] + (s[i - 1] == '_');
        rightSum[i] = rightSum[i - 1] + (s[i - 1] == '/');
    }
    for (int i = 0; i <= N; i++) {
        leftInd[i] = INF;
        midInd[i] = INF;
        rightInd[i] = INF;
    }
    for (int i = 1; i <= N; i++) {
        if (leftInd[leftSum[i]] == INF) leftInd[leftSum[i]] = i;
        if (midInd[midSum[i]] == INF) midInd[midSum[i]] = i;
        if (rightInd[rightSum[i]] == INF) rightInd[rightSum[i]] = i;
    }
    while (Q--) {
        solve();
    }
}
