#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
int leftRange[200001];
int rightRange[200001];
vector<int> adjList[200001];
int numVisited = 0;
long long arr[200001];
long long segTree[800001]; // 4 times size of N

void DFS(int node, int parent) {
    numVisited++;
    leftRange[node] = numVisited;
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
    }
    rightRange[node] = numVisited;
}

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
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1);
    for (int i = 1; i <= N; i++) {
        update(1, 1, N, leftRange[i], arr[i]); // Update from the left range of the node, not the node itself
    }
    while (Q--) {
        int t, s, x;
        cin >> t;
        if (t == 1) {
            cin >> s >> x;
            update(1, 1, N, leftRange[s], x);
        }
        else {
            cin >> s;
            cout << query(1, 1, N, leftRange[s], rightRange[s]) << "\n";
        }
    }
}
