#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int T, N, M, Q;
vector<int> binArr;
vector<int> valArr;
vector<int> segTree;

void build(int node, int L, int R) {
    if (L == R) {
        segTree[node] = valArr[L];
    }
    else {
        int mid = (L+R)/2;
        build(2*node, L, mid);
        build(2*node+1, mid+1, R);
        segTree[node] = max(segTree[2*node], segTree[2*node+1]);
    }
}

int query(int node, int tl, int tr, int L, int R) {
    if (R < tl || tr < L) return 0;
    if (L <= tl && tr <= R) return segTree[node];
    int tm = (tl+tr)/2;
    return max(query(2*node, tl, tm, L, R), query(2*node+1, tm+1, tr, L, R));
}

void solve() {
    cin >> N >> M;
    binArr.clear();
    binArr.resize(N+1);
    valArr.clear();
    valArr.resize(N+1);
    segTree.clear();
    segTree.resize(4*N+4);
    vector<pair<int, int>> seg(M);
    for (int i = 0; i < M; i++) {
        cin >> seg[i].f >> seg[i].s;
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int x;
        cin >> x;
        valArr[i] = i;
        binArr[i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        binArr[i] += binArr[i-1];
        cout << valArr[i] << " ";
    } cout << "\n";
    int ans = -1;
    for (auto [l, r]: seg) {
        if (binArr[r]-binArr[l-1] > r-l+1) {
            cout << l << " " << r << " " << query(1, 1, N, l, r) << "\n";
            ans = max(ans, query(1, 1, N, l, r));
        }
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
