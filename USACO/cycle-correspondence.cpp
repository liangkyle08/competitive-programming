#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int A[500001];
int B[500001];
int aInd[500001];
int bInd[500001];

int solve() {
    vector<int> shift(K);
    for (int i = 1; i <= K; i++) {
        if (!bInd[A[i]]) continue; // B doesn't have value of A
        shift[(bInd[A[i]]-aInd[A[i]]+K) % K]++;
    }
    int ans = 0;
    for (int i = 0; i < K; i++) {
        ans = max(ans, shift[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (aInd[i] || bInd[i]) continue;
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> A[i];
        aInd[A[i]] = i;
    }
    for (int i = 1; i <= K; i++) {
        cin >> B[i];
        bInd[B[i]] = i;
    }
    int ans = 0;
    ans = max(ans, solve());
    for (int i = 1; i <= K; i++) {
        bInd[B[i]] = K-i+1;
    }
    ans = max(ans, solve());
    cout << ans << "\n";
}