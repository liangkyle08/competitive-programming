#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;

void solve() {
    cin >> N;
    vector<long long> A(N+1), B(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin()+1, B.end(), greater<int>());
    vector<int> P(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    map<int, vector<int>> ind;
    for (int i = 1; i <= N; i++) {
        ind[B[i]].push_back(i);
    }
    vector<int> removeOrder(N+1);
    for (int i = 1; i <= N; i++) {
        removeOrder[i] = ind[A[P[i]]].back();
        ind[A[P[i]]].pop_back();
    }
    long long ans = 0;
    int finalK = 0;
    int cnt = 1;
    long long K = 1;
    int j = 1;
    vector<bool> seen(N+1);
    while (j <= N) {
        while (cnt < K && j <= N) {
            if (!seen[j]) {
                cnt++;
            }
            if (cnt == K) break;
            j++;
        }
        if (j > N) break;
        if (B[j]*K > ans) {
            ans = B[j]*K;
            finalK = K;
        }
        seen[removeOrder[K]] = true;
        if (removeOrder[K] <= j) cnt--;
        if (j == N) break;
        K++;
        j++;
    }
    cout << ans << " " << finalK << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
