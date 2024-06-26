#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int A[100001];
int B[100001];
int aInd[100001];
int bInd[100001];
int C[100001];
int segTree[400001]; // 4 times size of N

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
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        bInd[B[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        C[i] = bInd[A[i]];
    }
    vector<int> len(N+1);
    set<int> seen;
    seen.insert(0);
    for (int i = 1; i <= N; i++) {
        len[C[i]] = query(1, 1, N, 1, C[i])+1;
        update(1, 1, N, C[i], len[C[i]]);
    }
    int maxLen = 0;
    for (int i = 1; i <= N; i++) {
        maxLen = max(maxLen, len[i]);
    }
    cout << maxLen << "\n";
}
