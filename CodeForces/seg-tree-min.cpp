#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
int arr[200001];
pair<int, int> segTree[800001]; // minimum in segment, count of the minimum

void update(int node, int L, int R, int pos, int val) {
    if (L == R) {
        segTree[node].fi = val;
        segTree[node].se = 1;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        update(2*node, L, mid, pos, val);
    }
    else {
        update(2*node+1, mid+1, R, pos, val);
    }
    if (segTree[2*node].fi < segTree[2*node+1].fi) { // Left Child < Right Child
        segTree[node].fi = segTree[2*node].fi;
        segTree[node].se = segTree[2*node].se;
    }
    else if (segTree[2*node+1].fi < segTree[2*node].fi) { // Right Child < Left Child
        segTree[node].fi = segTree[2*node+1].fi;
        segTree[node].se = segTree[2*node+1].se;
    }
    else { // Left Child = Right Child
        segTree[node].fi = segTree[2*node].fi;
        segTree[node].se = segTree[2*node].se+segTree[2*node+1].se;
    }
}

pair<int, int> query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return {(1<<30), 0};
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node];
    }
    int mid = (L + R) / 2;
    pair<int, int> q1 = query(2*node, L, mid, Lq, Rq);
    pair<int, int> q2 = query(2*node+1, mid+1, R, Lq, Rq);
    if (q1.fi < q2.fi) {
        return q1;
    }
    else if (q2.fi < q1.fi) {
        return q2;
    }
    else {
        return {q1.fi, q1.se+q2.se};
    }
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
            pair<int, int> ans = query(1, 1, N, a+1, b);
            cout << ans.fi << '\n';
        }
    }
}
