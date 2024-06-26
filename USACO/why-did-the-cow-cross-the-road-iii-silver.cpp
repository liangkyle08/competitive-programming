#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K, R;
map<array<int, 4>, bool> roads;
pair<int, int> cows[101];
bool isCow[101][101];
bool seen[101][101];
vector<pair<int, int>> add = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int comp;

void DFS(int r1, int c1) {
    if (seen[r1][c1]) return;
    seen[r1][c1] = true;
    comp += isCow[r1][c1];
    for (auto [rAdd, cAdd]: add) {
        int r2 = r1+rAdd;
        int c2 = c1+cAdd;
        if (r2 > N || r2 < 1 || c2 > N || c2 < 1) continue;
        if (roads[{r1, c1, r2, c2}]) continue;
        DFS(r2, c2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> N >> K >> R;
    for (int i = 1; i <= R; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        roads[{r1, c1, r2, c2}] = true;
        roads[{r2, c2, r1, c1}] = true;
    }
    for (int i = 1; i <= K; i++) {
        cin >> cows[i].fi >> cows[i].se;
        isCow[cows[i].fi][cows[i].se] = true;
    }
    int ans = 0;
    for (int i = 1; i <= K; i++) {
        if (!seen[cows[i].fi][cows[i].se]) {
            comp = 0;
            DFS(cows[i].fi, cows[i].se);
            ans += comp*(K-comp);
        }
    }
    cout << ans/2 << "\n";
}
