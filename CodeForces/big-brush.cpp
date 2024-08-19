#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 1000;

int N, M;
int A[MAX_N + 5][MAX_N + 5];
bool seen[MAX_N + 5][MAX_N + 5];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }
    queue<pair<int, int>> q;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (A[i][j] == A[i][j + 1]
                && A[i][j] == A[i + 1][j]
                && A[i][j] == A[i + 1][j + 1]) {
                q.push({i, j});
            }
        }
    }
    vector<tuple<int, int, int>> ans;
    while (!q.empty()) {
        int i = q.front().fi;
        int j = q.front().se;
        q.pop();
        if (seen[i][j]
            && seen[i][j + 1]
            && seen[i + 1][j]
            && seen[i + 1][j + 1]) {
            continue;
        }
        if (!seen[i][j]) ans.push_back({i, j, A[i][j]});
        else if (!seen[i][j + 1]) ans.push_back({i, j, A[i][j + 1]});
        else if (!seen[i + 1][j]) ans.push_back({i, j, A[i + 1][j]});
        else ans.push_back({i, j, A[i + 1][j + 1]});
        seen[i][j] = true;
        seen[i][j + 1] = true;
        seen[i + 1][j] = true;
        seen[i + 1][j + 1] = true;
        for (int i2 = i - 1; i2 <= i + 1; i2++) {
            for (int j2 = j - 1; j2 <= j + 1; j2++) {
                if (i2 < 1 || i2 > N - 1) continue;
                if (j2 < 1 || j2 > M - 1) continue;
                if (i2 == 0 && j2 == 0) continue;
                set<int> s;
                if (!seen[i2][j2]) s.insert({A[i2][j2]});
                if (!seen[i2][j2 + 1]) s.insert({A[i2][j2 + 1]});
                if (!seen[i2 + 1][j2]) s.insert({A[i2 + 1][j2]});
                if (!seen[i2 + 1][j2 + 1]) s.insert({A[i2 + 1][j2 + 1]});
                if ((int)s.size() >= 2) continue;
                q.push({i2, j2});
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            flag &= seen[i][j];
        }
    }
    if (!flag) {
        cout << -1 << "\n";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    cout << (int)ans.size() << "\n";
    for (auto &[i, j, c]: ans) {
        cout << i << " " << j << " " << c << "\n";
    }
}
