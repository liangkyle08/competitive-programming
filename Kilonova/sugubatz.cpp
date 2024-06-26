#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);

int N, X;
int A[1000001];
vector<int> freq[1000001];
int B[1000001];
int suffix[1000005];
int seen[1000001];
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
    cin >> N >> X;
    int maxValA = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        freq[A[i]].push_back(i);
        maxValA = max(maxValA, A[i]);
        B[i] = 1;
    }
    for (int i = maxValA; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j <= maxValA; j += i) {
            cnt += (int)freq[j].size();
        }
        if (cnt < 2) {
            continue;
        }
        for (int j = i; j <= maxValA; j += i) {
            for (auto k: freq[j]) {
                B[k] = max(B[k], i);
            }
        }
    }
    int maxValB = 0;
    for (int i = 1; i <= N; i++) {
        suffix[B[i]]++;
        maxValB = max(maxValB, B[i]);
    }
    for (int i = maxValB; i >= 1; i--) {
        update(1, 1, N, i, suffix[i]);
    }
    long long ans = 0LL;
    for (int i = 1; i <= N; i++) {
        int val = max(X-B[i], 1);
        ans += query(1, 1, N, val, maxValB);
        if (B[i] >= val) {
            ans -= (B[i] < X);
        }
        cout << query(1, 1, N, val, maxValB)-(B[i] < X)*(B[i] >= val) << "\n";
        suffix[B[i]]--;
        update(1, 1, N, i, suffix[B[i]]);
    }
    cout << ans << "\n";
}
