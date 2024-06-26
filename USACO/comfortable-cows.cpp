#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int X[100001];
int Y[100001];
map<int, map<int, int>> grid;
vector<pair<int, int>> add = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
    }
    queue<pair<pair<int, int>, int>> q;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        map<int, map<int, int>> seen;
        q.push({{X[i], Y[i]}, 2});
        while (!q.empty()) {
            int x = q.front().fi.fi;
            int y = q.front().fi.se;
            int check = q.front().se;
            q.pop();
            bool flag = false;
            if (grid[x][y] == 1 && check == 2) {
                cnt--;
                grid[x][y] = check;
                flag = true;
            }
            if (grid[x][y] == 0 && check == 1) {
                cnt++;
                grid[x][y] = check;
                flag = true;
            }
            if (grid[x][y] == 0 && check == 2) {
                grid[x][y] = check;
                flag = true;
            }
            // Is current cow comfortable?
            int adj = 0;
            for (auto [u, v]: add) {
                if (grid[x+u][y+v] > 0) {
                    adj++;
                }
            }
            if (adj == 3) {
                for (auto [u, v]: add) {
                    if (grid[x+u][y+v] == 0) {
                        q.push({{x+u, y+v}, 1});
                        break;
                    }
                }
            }
            // Adjacent Cows
            if (!flag) continue;
            for (auto [u, v]: add) {
                if (grid[x+u][y+v] > 0) {
                    q.push({{x+u, y+v}, 1});
                }
            }
        }
        cout << cnt << "\n";
    }
}
