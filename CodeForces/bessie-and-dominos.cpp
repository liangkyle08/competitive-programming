#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
int arr[500][500];
int t[500][500];

int DFS(int node, int parent, int val) {
    int x = node / 1000;
    int y = node % 1000;
    int cur = arr[x][y];
    if (x-2 >= 1 && t[x-1][y] == 2) {
        int x2 = x-2;
        int child = x2*1000+y;
        if (child != parent) {
            cur += DFS(child, node, val);
        }
    }
    if (x+2 <= N && t[x+1][y] == 2) {
        int x2 = x+2;
        int child = x2*1000+y;
        if (child != parent) {
            cur += DFS(child, node, val);
        }
    }
    if (y-2 >= 1 && t[x][y-1] == 1) {
        int y2 = y-2;
        int child = x*1000+y2;
        if (child != parent) {
            cur += DFS(child, node, val);
        }
    }
    if (y+2 <= M && t[x][y+1] == 1) {
        int y2 = y+2;
        int child = x*1000+y2;
        if (child != parent) {
            cur += DFS(child, node, val);
        }
    }
    return max(val, cur);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> M;
    int start = 0;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            if (s[j-1] == '<' || s[j-1] == '>') t[i][j] = 1;
            if (s[j-1] == '^' || s[j-1] == 'v') t[i][j] = 2;
            if (s[j-1] == '.') {
                start = i*1000+j;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    cout << DFS(start, -1, 0) << "\n";
}