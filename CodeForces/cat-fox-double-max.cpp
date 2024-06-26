#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int P[100001];
int A[100001];
int B[100001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    vector<pair<int, int>> evenIndex, oddIndex;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            evenIndex.push_back({P[i], i});
        }
        else {
            oddIndex.push_back({P[i], i});
        }
    }
    sort(evenIndex.begin(), evenIndex.end());
    sort(oddIndex.begin(), oddIndex.end());
    for (int i = 1; i <= N/2; i++) {
        A[oddIndex.back().se] = i;
        B[oddIndex.back().se] = i+N/2;
        oddIndex.pop_back();
        A[evenIndex.back().se] = i+N/2;
        B[evenIndex.back().se] = i;
        evenIndex.pop_back();
    }
    int aCnt = 0;
    int bCnt = 0;
    for (int i = 2; i < N; i++) {
        if (P[i]+A[i] > P[i-1]+A[i-1] && P[i]+A[i] > P[i+1]+A[i+1]) {
            aCnt++;
        }
        if (P[i]+B[i] > P[i-1]+B[i-1] && P[i]+B[i] > P[i+1]+B[i+1]) {
            bCnt++;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << (aCnt >= bCnt ? A[i] : B[i]) << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
