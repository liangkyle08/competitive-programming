#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int P;
long long N, K, R, T;

long long getIndex(long long X) {
    long long leftInd = (X-R+N*(R/N+1)) % N;
    long long rightInd = (X+R) % N;
    if (leftInd % 2 == 0) return leftInd;
    return rightInd;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("asort.in", "r", stdin);
    freopen("asort.out", "w", stdout);
    cin >> P >> N >> R >> K >> T;
    if (P == 1) {
        cout << getIndex(K-1)+1 << "\n";
    }
    else {
        long long ind;
        if (T % 2 == 1) {
            ind = (T+R-1) % N;
        }
        else {
            ind = (T-R+N*(R/N+1)-1) % N;
        }
        cout << getIndex((ind+N-1) % N)+1 << " " << getIndex((ind+1) % N)+1 << "\n";
    }
}
