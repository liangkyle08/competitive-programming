#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[1005][1005];
pair<int, int> add[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool seen[1005][1005];
int curArea = 0;
int curPerm = 0;

void DFS(int x, int y) {
    if (x > N || x < 1 || y > N || y < 1) return;
    if (!arr[x][y]) return;
    if (seen[x][y]) return;
    seen[x][y] = true;
    curArea++;
    for (auto [xAdd, yAdd]: add) {
        if (!arr[x+xAdd][y+yAdd]) {
            curPerm++;
        }
        DFS(x+xAdd, y+yAdd);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            arr[i][j] = (s[j-1] == '#');
        }
    }
    int finalArea = 0;
    int finalPerm = (1<<30);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (seen[i][j]) continue;
            if (!arr[i][j]) continue;
            curArea = 0;
            curPerm = 0;
            DFS(i, j);
            if (curArea > finalArea
                || (curArea == finalArea && curPerm < finalPerm)) {
                finalArea = curArea;
                finalPerm = curPerm;
            }
        }
    }
    cout << finalArea << " " << finalPerm << "\n";
}
