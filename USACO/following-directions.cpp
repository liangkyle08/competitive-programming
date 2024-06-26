#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int N, Q;
int dir[1505][1505]; // 1 = R, 0 = D
int DP[1505][1505];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            dir[i][j] = (s[j-1] == 'R');
        }
        cin >> dir[i][N+1];
    }
    for (int j = 1; j <= N; j++) {
        cin >> dir[N+1][j];
    }
    int ans = 0;
    for (int i = 1; i <= N+1; i++) {
        for (int j = 1; j <= N+1; j++) {
            if (i > N || j > N) {
                ans += DP[i][j]*dir[i][j];
                continue;
            }
            DP[i][j]++;
            if (dir[i][j]) {
                DP[i][j+1] += DP[i][j];
            }
            else {
                DP[i+1][j] += DP[i][j];
            }
        }
    }
    cout << ans << "\n";
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        dir[x][y] = !dir[x][y];
        queue<pair<pair<int, int>, int>> q;
        if (dir[x][y]) {
            q.push({{x, y+1}, DP[x][y]});
            q.push({{x+1, y}, -DP[x][y]});
        }
        else {
            q.push({{x, y+1}, -DP[x][y]});
            q.push({{x+1, y}, DP[x][y]});
        }
        while (!q.empty()) {
            int x2 = q.front().fi.fi;
            int y2 = q.front().fi.se;
            int add = q.front().se;
            q.pop();
            if (x2 > N || y2 > N) {
                ans += add*dir[x2][y2];
                continue;
            }
            DP[x2][y2] += add;
            if (dir[x2][y2]) {
                q.push({{x2, y2+1}, add});
            }
            else {
                q.push({{x2+1, y2}, add});
            }
        }
        cout << ans << "\n";
    }
}