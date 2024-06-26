#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
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
    segTree[node] = max(segTree[2*node], segTree[2*node+1]);
}

int query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return 0LL;
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node];
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
    arr[N+1] = (1<<30);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            update(1, 1, N, a+1, b);
        }
        else {
            int x;
            cin >> x;
            int high = N+1;
            int low = 1;
            while (low < high) {
                int mid = (high+low)/2;
                if (query(1, 1, N, 1, mid) >= x) {
                    high = mid;
                }
                else {
                    low = mid+1;
                }
            }
            if (low-1 == N) {
                cout << -1 << "\n";
                continue;
            }
            cout << low-1 << "\n";
        }
    }
}
