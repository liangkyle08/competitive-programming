#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

int N, M;
int parent[MAX_N+5];
int sz[MAX_N+5];

int Find(int x) {
    if (x == parent[x]) {
        return x;
    }
    parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int a, int b) {
    if (a == b) return;
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        Union(Find(a), Find(b));
    }
}