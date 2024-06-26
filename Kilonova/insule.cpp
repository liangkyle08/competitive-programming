#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);

int N, M;
int arr[101][101];
int cc[4];
bool seen[101][101];
int minDist[101][101];
vector<pair<int, int>> add = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void DFS(int i, int j, int x) {
    if (arr[i][j] != x || seen[i][j]) return;
    seen[i][j] = true;
    for (auto [u, v]: add) {
        if (1 <= i+u && i+u <= N
            && 1 <= j+v && j+v <= M) {
            DFS(i+u, j+v, x);
        }
    }
}

void findCC(int x) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == x && !seen[i][j]) {
                cc[x]++;
                DFS(i, j, x);
            }
        }
    }
}

int findMinDist() {
    int totalMinDist = (1<<30);
    queue<pair<pair<int, int>, pair<int, int>>> q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 1) {
                q.push({{i, j}, {0, 1}});
                minDist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int i = q.front().fi.fi;
        int j = q.front().fi.se;
        int curDist = q.front().se.fi;
        bool flag = q.front().se.se;
        q.pop();
        if (minDist[i][j] != INF && !flag) continue;
        minDist[i][j] = curDist;
        if (arr[i][j] == 2) {
            if (minDist[i][j] > 1) {
                totalMinDist = min(totalMinDist, minDist[i][j]-1);
            }
            else {
                minDist[i][j] = INF;
            }
        }
        if (arr[i][j] != 0 && !flag) continue;
        for (auto [u, v]: add) {
            if (1 <= i+u && i+u <= N
                && 1 <= j+v && j+v <= M) {
                q.push({{i+u, j+v}, {curDist+1, 0}});
            }
        }
    }
    return totalMinDist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("insule.in", "r", stdin);
    freopen("insule.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            arr[i][j] = s[j-1]-'0';
            minDist[i][j] = INF;
        }
    }
    for (int i = 1; i <= 3; i++) {
        findCC(i);
        cout << cc[i] << " ";
    }
    cout << findMinDist() << "\n";
}
