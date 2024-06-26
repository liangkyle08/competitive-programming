#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long A[100001];
long long B[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("teleport.in", "r", stdin);
    //freopen("teleport.out", "w", stdout);
    cin >> N;
    long long ansC = 0LL;
    long long ansL = 0LL;
    long long ansR = 0LL;
    vector<long long> L;
    vector<long long> R;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        ansC += abs(A[i]-B[i]);
        bool flag = true;
        if (A[i] <= 0 && B[i] >= 0 || A[i] >= 0 && B[i] <= 0) {
            flag = false;
        }
        else {
            ansL += abs(A[i]-B[i]);
            ansR += abs(A[i]-B[i]);
        }
        if (flag) continue;
        if (B[i] > A[i]) { // Right
            ansR += abs(A[i]);
            R.push_back(abs(B[i]));
            ansL += abs(A[i]-B[i]);
        }
        if (B[i] < A[i]) { // Left
            ansL += abs(A[i]);
            L.push_back(abs(B[i]));
            ansR += abs(A[i]-B[i]);
        }
    }
    cout << ansC << " " << ansL << " " << ansR << "\n";
    sort(R.begin(), R.end());
    sort(L.begin(), L.end());
    long long mid = 0;
    if (!R.empty()) mid = R[(int)R.size()/2];
    for (int i = 0; i < (int)R.size(); i++) {
        ansR += abs(R[i]-mid);
    }
    mid = 0;
    if (!L.empty()) mid = L[(int)L.size()/2];
    for (int i = 0; i < (int)L.size(); i++) {
        ansL += abs(L[i]-mid);
    }
    cout << min(ansC, min(ansL, ansR)) << "\n";
}
