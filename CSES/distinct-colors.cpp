#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[200001];
int leftRange[200001];
int rightRange[200001];
vector<int> adjList[200001];
int numVisited = 0;
int segTree[800001]; // 4 times size of N
map<int, int> curPos; // curPosition of each color
int ans[200001];

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

void DFS(int node, int parent) {
    numVisited++;
    leftRange[node] = numVisited;
    if (curPos[arr[node]] > 0) {
        update(1, 1, N, leftRange[curPos[arr[node]]], 0);
    }
    update(1, 1, N, leftRange[node], 1);
    curPos[arr[node]] = node;
    for (auto child: adjList[node]) {
        if (parent == child) continue;
        DFS(child, node);
    }
    rightRange[node] = numVisited;
    ans[node] = query(1, 1, N, leftRange[node], rightRange[node]);
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
    DFS(1, -1);
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}
