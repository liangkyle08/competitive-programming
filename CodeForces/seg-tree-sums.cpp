#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
long long arr[200001];
long long segTree[800001]; // 4 times size of N

void update(int node, int L, int R, int pos, int val) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(1, 1, N, i, arr[i]);
    }
    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            update(1, 1, N, a+1, b);
        }
        else {
            cout << query(1, 1, N, a+1, b) << '\n';
        }
    }
}
