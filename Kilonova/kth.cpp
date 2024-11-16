#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 3e5;
const int MAX_V = 1e5 + 5;

int N, kPos, length, Q;
int A[MAX_N + 5];
int segTree[4 * MAX_V + 5];
int ans[MAX_N + 5];

void update(int node, int L, int R, int pos, int val) {
    if (L == R) {
        segTree[node] += val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        update(2 * node, L, mid, pos, val);
    }
    else {
        update(2 * node + 1, mid + 1, R, pos, val);
    }
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return 0LL;
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node];
    }
    int mid = (L + R) / 2;
    return query(2 * node, L, mid, Lq, Rq) + query(2 * node + 1, mid + 1, R, Lq, Rq);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    cin >> N >> kPos >> length;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += 5e4 + 1;
    }
    for (int i = 1; i <= N; i++) {
        update(1, 1, MAX_V, A[i], 1);
        if (i > length) {
            update(1, 1, MAX_V, A[i - length], -1);
        }
        if (i >= length) {
            int low = 1;
            int high = MAX_V;
            while (low < high) {
                int mid = (low + high) / 2;
                int curQuery = query(1, 1, MAX_V, 1, mid);
                if (curQuery >= kPos) {
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }
            ans[i - length + 1] = low - 5e4 - 1;
        }
    }
    cin >> Q;
    while (Q--) {
        int v;
        cin >> v;
        cout << ans[v] << "\n";
    }
}
