#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, Q;
int arr[500001];
vector<int> adjList[500001];
int leftRange[500001];
int rightRange[500001];
int curPos = 0;
pair<long long, int> segTree[2000001]; // sum, last value index
int nodeVal[500001];
int tempLast[500001];
int finalLast[500001];

void build(int node, int L, int R) {
    if (L == R) {
        segTree[node].fi += arr[nodeVal[L]];
        segTree[node].se = finalLast[L];
        return;
    }
    int mid = (L + R) / 2;
    build(2*node, L, mid);
    build(2*node+1, mid+1, R);
    segTree[node].fi = segTree[2*node].fi+segTree[2*node+1].fi;
    segTree[node].se = max(segTree[2*node].se, segTree[2*node+1].se);
}

pair<long long, int> query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return {0, 0};
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node];
    }
    int mid = (L + R) / 2;
    pair<long long, int> A = query(2*node, L, mid, Lq, Rq);
    pair<long long, int> B = query(2*node+1, mid+1, R, Lq, Rq);
    return {A.fi+B.fi, max(A.se, B.se)};
}

void DFS(int node, int parent) {
    curPos++;
    leftRange[node] = curPos;
    nodeVal[curPos] = node;
    for (auto child: adjList[node]) {
        if (parent == child) continue;
        DFS(child, node);
    }
    rightRange[node] = curPos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, 0);
    for (int i = 1; i <= N; i++) {
        finalLast[i] = tempLast[arr[nodeVal[i]]];
        tempLast[arr[nodeVal[i]]] = i;
    }
    build(1, 1, N);
    cin >> Q;
    while (Q--) {
        int x;
        cin >> x;
        pair<long long, int> result = query(1, 1, N, leftRange[x], rightRange[x]);
        int len = rightRange[x]-leftRange[x]+1;
        if (result.fi == 1LL*len*(len+1)/2 && result.se < leftRange[x]) {
            cout << "DA\n";
            continue;
        }
        cout << "NU\n";
    }
}
