#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
char dir[300001];
int L[300001];
int R[300001];
int minOp[300001];

void DFS(int node) {
    if (L[node]) {
        DFS(L[node]);
        minOp[node] = min(minOp[node], minOp[L[node]]+(dir[node] != 'L'));
    }
    if (R[node]) {
        DFS(R[node]);
        minOp[node] = min(minOp[node], minOp[R[node]]+(dir[node] != 'R'));
    }
    if (L[node] == 0 && R[node] == 0) minOp[node] = 0;
}

void solve() {
    cin >> N;
    string s;
    cin >> s;
    for (int i = 1; i <= N; i++) {
        minOp[i] = (1<<30);
    }
    for (int i = 1; i <= N; i++) {
        dir[i] = s[i-1];
    }
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
    }
    DFS(1);
    cout << minOp[1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
