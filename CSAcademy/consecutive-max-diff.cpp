#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

long long maxDifference(const vector<int>& v) {
    int N = (int)v.size();
    if (N == 1) return 0LL;
    long long mx = -(1LL<<60);
    long long mn = (1LL<<60);
    for (int i = 0; i < N; i++) {
        mx = max(mx, 1LL*v[i]);
        mn = min(mn, 1LL*v[i]);
    }
    long long len = (mx - mn + (1LL * N - 2LL)) / (1LL * N - 1LL);
    if (mx-mn == 0LL) return 0LL;
    vector<long long> divMin, divMax;
    for (int i = mn; i <= mx; i += len) {
        divMax.push_back(-(1LL<<60));
        divMin.push_back((1LL<<60));
    }
    for (int i = 0; i < N; i++) {
        int ind = (v[i] - mn) / len;
        divMax[ind] = max(divMax[ind], 1LL*v[i]);
        divMin[ind] = min(divMin[ind], 1LL*v[i]);
    }
    int M = (int)divMin.size();
    long long ans = 0LL;
    long long cur = -(1LL<<60);
    int j = 0;
    while (j < M && cur == -(1LL<<60)) {
        cur = divMin[j];
        j++;
    }
    while (j < M) {
        if (divMin[j] != (1LL<<60)) {
            ans = max(ans, divMin[j]-cur);
            cur = divMax[j];
        }
        j++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << maxDifference(A) << "\n";
}
