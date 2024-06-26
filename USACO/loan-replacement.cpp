#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;



bool check(long long N, long long K, long long M, long long X) {
    long long G = 0;
    while (K > 0 && G < N) {
        long long Y = (N-G)/X;
        if (Y < M) {
            return ((N-G+M-1)/M) <= K;
        }
        long long numDays = (N-X*Y-G)/Y+1;
        if (numDays > K) numDays = K;
        G += Y*numDays;
        K -= numDays;
    }
    return G >= N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    long long N, K, M;
    cin >> N >> K >> M;
    long long low = 1;
    long long high = 1e12;
    while (low < high) {
        long long mid = (low+high+1)/2;
        if (check(N, K, M, mid)) {
            low = mid;
        }
        else {
            high = mid-1;
        }
    }
    cout << low << "\n";
}
