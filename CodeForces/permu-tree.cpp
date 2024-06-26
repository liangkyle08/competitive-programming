#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
vector<int> adjList[5001];
long long subTree[5001];
long long ans = 0LL;

void DFS(int node, int parent) {
    subTree[node] = 1;
    int DP[5001];
    DP[0] = true;
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        subTree[node] += subTree[child];
        for (int i = subTree[node]-1; i >= 0; i--) {
            if (DP[i]) {
                DP[i+subTree[child]] = true;
            }
        }
    }
    long long maxProduct = 0;
    for (int i = 0; i < subTree[node]; i++) {
        if (DP[i]) {
            maxProduct = max(maxProduct, i*(subTree[node]-i-1));
        }
    }
    ans += maxProduct;
}

int main() {
    cin >> N;
    for (int u = 2; u <= N; u++) {
        int v;
        cin >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(1, -1);
    cout << ans << "\n";
}
