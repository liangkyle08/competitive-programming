#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

struct Node {
    long long G, L, R, S;
};

int N, Q;
long long arr[200001];
Node segTree[800001]; // 4 times size of N

void update(int node, int L, int R, int pos, long long val) {
    if (L == R) {
        segTree[node] = {val, val, val, val};
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        update(2*node, L, mid, pos, val);
    }
    else {
        update(2*node+1, mid+1, R, pos, val);
    }
    Node u = segTree[2*node];
    Node v = segTree[2*node+1];
    segTree[node].G = max(u.G, max(v.G, u.R+v.L));
    segTree[node].L = max(u.L, u.S+v.L);
    segTree[node].R = max(u.R+v.S, v.R);
    segTree[node].S = u.S+v.S;
}

long long query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return 0LL;
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node].G;
    }
    int mid = (L + R) / 2;
    return max(query(2*node, L, mid, Lq, Rq), query(2*node+1, mid+1, R, Lq, Rq));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(1, 1, N, i, arr[i]);
    }
    cout << max(query(1, 1, N, 1, N), 0LL) << '\n';
    while (Q--) {
        int a, b;
        cin >> a >> b;
        update(1, 1, N, a+1, b);
        cout << max(query(1, 1, N, 1, N), 0LL) << '\n';
    }
}
