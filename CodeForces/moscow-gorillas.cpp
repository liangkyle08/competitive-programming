#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

long long N;
int A[200001];
int B[200001];
long long aInd[200001];
long long bInd[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        aInd[A[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        bInd[B[i]] = i;
    }
    long long L = min(aInd[1], bInd[1]);
    long long R = max(aInd[1], bInd[1]);
    long long ans = (L-1)*L/2+(N-R)*(N-R+1)/2+(R-L-1)*(R-L)/2;
    for (int mex = 2; mex <= N; mex++) {
        if ((L <= aInd[mex] && aInd[mex] <= R)
            || (L <= bInd[mex] && bInd[mex] <= R)) {
            L = min(L, min(aInd[mex], bInd[mex]));
            R = max(R, max(aInd[mex], bInd[mex]));
            continue;
        }
        long long leftInd = 0;
        long long rightInd = N+1;
        if (aInd[mex] > R) rightInd = min(rightInd, aInd[mex]);
        if (bInd[mex] > R) rightInd = min(rightInd, bInd[mex]);
        if (aInd[mex] < L) leftInd = max(leftInd, aInd[mex]);
        if (bInd[mex] < L) leftInd = max(leftInd, bInd[mex]);
        ans += (L-leftInd)*(rightInd-R);
        L = min(L, min(aInd[mex], bInd[mex]));
        R = max(R, max(aInd[mex], bInd[mex]));
    }
    cout << ans+1 << "\n";
}
