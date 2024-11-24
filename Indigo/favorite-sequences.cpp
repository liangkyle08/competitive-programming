#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const long long MOD = (long long)(1e9+7);

const int MAX_N = 1e5;

int N, X;
long long A[MAX_N + 5];
long long segTree[4 * MAX_N + 5];
long long leftCnt[MAX_N + 5];
long long rightCnt[MAX_N + 5];

long long mul(long long x, long long y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

long long add(long long x, long long y) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

void update(int node, int L, int R, int pos, long long val) {
    if (L == R) {
        segTree[node] = val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        update(2 * node, L, mid, pos, val);
    }
    else {
        update(2 * node + 1, mid + 1, R, pos, val);
    }
    segTree[node] = add(segTree[2 * node], segTree[2 * node + 1]);
}

long long query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return 0LL;
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node];
    }
    int mid = (L + R) / 2;
    return add(query(2 * node, L, mid, Lq, Rq), query(2 * node + 1, mid + 1, R, Lq, Rq));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> X;
    long long maxA = 0LL;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }
    for (int i = 1; i <= N; i++) {
        long long sum = 1LL;
        if (A[i] > 1) sum = add(sum, query(1, 1, maxA, max(A[i] - X, 1LL), A[i] - 1));
        if (A[i] < maxA) sum = add(sum, query(1, 1, maxA, A[i] + 1, min(A[i] + X, maxA)));
        leftCnt[i] = sum;
        long long cur = query(1, 1, maxA, A[i], A[i]) % MOD;
        update(1, 1, maxA, A[i], add(cur, leftCnt[i]));
    }
    for (int i = 1; i <= N; i++) {
        update(1, 1, maxA, A[i], 0LL);
    }
    for (int i = N; i >= 1; i--) {
        long long sum = 1LL;
        if (A[i] > 1) sum = add(sum, query(1, 1, maxA, max(A[i] - X, 1LL), A[i] - 1));
        if (A[i] < maxA) sum = add(sum, query(1, 1, maxA, A[i] + 1, min(A[i] + X, maxA)));
        rightCnt[i] = sum;
        long long cur = query(1, 1, maxA, A[i], A[i]) % MOD;
        update(1, 1, maxA, A[i], add(cur, rightCnt[i]));
    }
    long long ans = 0LL;
    for (int i = 1; i <= N; i++) {
        cout << leftCnt[i] << " " << rightCnt[i] << " " << A[i] << "\n";
        ans = add(ans, mul(mul(leftCnt[i], rightCnt[i]), A[i]));
    }
    cout << (ans % MOD) << "\n";
}
