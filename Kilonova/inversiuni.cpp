#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long arr[200001];
long long segTree[800001];

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("inversiuni.in", "r", stdin);
    freopen("inversiuni.out", "w", stdout);
    cin >> N;
    long long ans = 0LL;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        long long L = query(1, 1, N, 1, arr[i]-1);
        long long R = i-L-1;
        ans += min(L, R);
        update(1, 1, N, arr[i], 1);
    }
    cout << ans << "\n";
}
