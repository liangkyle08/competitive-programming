#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
long long S, T;
long long total = 0;
int A[200001];
long long diff[200001];
long long segTree[800001]; // 4 times size of N

void update(int node, int L, int R, int pos, long long val) {
    if (L == R) {
        segTree[node] = val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        update(2*node, L, mid, pos, val);
    }
    else {
        update(2*node+1, mid+1, R, pos, val);
    }
    segTree[node] = segTree[2*node]+segTree[2*node+1];
}

long long query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return 0LL;
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node];
    }
    int mid = (L + R) / 2;
    return query(2*node, L, mid, Lq, Rq)+query(2*node+1, mid+1, R, Lq, Rq);
}

long long check(int ind) {
    int u = A[ind]+query(0, 0, N, 0, ind);
    int v = A[ind+1]+query(0, 0, N, 0, ind+1);
    if (u < v) {
        return -S*(v-u);
    }
    else {
        return T*(u-v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q >> S >> T;
    for (int i = 0; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        total += check(i);
    }
    while (Q--) {
        int L, R;
        long long X;
        cin >> L >> R >> X;
        total -= check(L);
        if (R < N) {
            total -= check(R);
        }
        diff[L] += X;
        update(0, 0, N, L, diff[L]);
        if (R < N) {
            diff[R+1] -= X;
            update(0, 0, N, R+1, diff[R+1]);
        }
        total += check(L);
        if (R < N) {
            total += check(R);
        }
        cout << total << "\n";
        for (int i = 0; i <= N; i++) {
            cout << i << " " << query(0, 0, N, 0, 0) << "\n";
        }
    }
}
