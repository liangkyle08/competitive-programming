#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int goTo[100001];
set<int> passed[100001];
int ans[100001];
bool seen[100001];
set<int> setUnion;

void DFS(int u) {
    if (seen[u]) return;
    seen[u] = true;
    for (auto v: passed[u]) setUnion.insert(v);
    DFS(goTo[u]);
    ans[u] = (int)setUnion.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        goTo[i] = i;
        passed[i].insert(i);
    }
    while (K--) {
        int a, b;
        cin >> a >> b;
        swap(goTo[a], goTo[b]);
        passed[goTo[a]].insert(a);
        passed[goTo[b]].insert(b);
    }
    for (int i = 1; i <= N; i++) {
        if (!seen[i]) {
            setUnion.clear();
            DFS(i);
        }
        cout << ans[i] << "\n";
    }
}
