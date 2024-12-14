#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int MAX_N = 1e5;

int T, N, Q, C;
long long segTree[4 * MAX_N + 5];

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
    segTree[node] = max(segTree[2*node], segTree[2*node+1]);
}

long long query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return 0LL;
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node];
    }
    int mid = (L + R) / 2;
    return max(query(2*node, L, mid, Lq, Rq), query(2*node+1, mid+1, R, Lq, Rq));
}

bool cmp(pair<int, int> A, pair<int, int> B) {
    if (A.se == B.se) return A.fi < B.fi;
    return A.se < B.se;
}

void solve() {
    cin >> N >> Q >> C;
    vector<int> arr(N + 1);
    vector<bool> fixed(N + 1);
    vector<int> mx(N + 1);
    vector<int> maxPos(N + 1);
    vector<pair<int, int>> queries(Q);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] > 0) fixed[i] = true;
        if (arr[i] == 0) arr[i] = 1;
        maxPos[i] = (1 << 30);
        update(1, 1, N, i, arr[i]);
    }
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].fi >> queries[i].se;
    }
    sort(queries.begin(), queries.end(), cmp);
    bool flag = false;
    for (auto [a, h]: queries) {
        int max1 = 0;
        int max2 = 0;
        max1 = query(1, 1, N, 1, a);
        if (a + 1 <= h - 1) max2 = query(1, 1, N, a + 1, h - 1);
        if (max2 == C) {
            flag = true;
            break;
        }
        if (max1 < max2) {
            bool flag2 = true;
            for (int i = a; i >= 1; i--) {
                if (fixed[i]) continue;
                if (max2 > maxPos[i]) continue;
                arr[i] = max2;
                update(1, 1, N, i, max2);
                flag2 = false;
                break;
            }
            if (flag2) {
                flag = true;
                break;
            }
        }
        if (arr[h] <= max1) {
            if (fixed[h]) {
                flag = true;
                break;
            }
            else {
                if (max1+1 > C) {
                    flag = true;
                    break;
                }
                arr[h] = max1+1;
                update(1, 1, N, h, max1+1);
            }
        }
        for (int i = 1; i <= h-1; i++) {
            maxPos[i] = arr[h]-1;
        }
    }
    if (flag) {
        cout << -1 << "\n";
        return;
    }
    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ((i < N) ? " " : "\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}

/*
    int curMax = 0;
    bool flag = false;
    for (auto [a, h]: query) {
        if (mx[h-1] > mx[a]) {
            curMax = max(curMax, mx[h-1]);
            for (int i = a; i >= 1; i--) {
                if (!fixed[i]) {

                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 0) arr[i] = 1;
        cout << arr[i] << " ";
    } cout << "\n";
 */
