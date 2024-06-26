#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
int arr[200001];
int segTree[800001]; // 4 times size of N

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

int query(int node, int L, int R, int Lq, int Rq) {
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
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(1, 1, N, i, arr[i]);
    }
    while (M--) {
        int t, v;
        cin >> t >> v;
        v++; // Zero-index to one-index
        if (t == 1) {
            arr[v] = !arr[v];
            update(1, 1, N, v, arr[v]);
            continue;
        }
        int high = N;
        int low = 0;
        while (low < high) {
            int mid = (low+high)/2;
            if (query(1, 1, N, 1, mid) >= v) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        cout << low-1 << "\n";
    }
}
