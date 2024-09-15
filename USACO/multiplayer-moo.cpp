#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 250;
const int MAX_A = 1e6;

int N;
int A[MAX_N + 5][MAX_N + 5];
int maxComp[MAX_A + 5];
int total[MAX_A + 5];
bool seen[MAX_N + 5][MAX_N + 5];
int maxComp2;
int cnt;

bool cmp(int X, int Y) {
    return total[X] > total[Y];
}

void DFS(int x, int y) {
    if (seen[x][y]) return;
    seen[x][y] = true;
    cnt++;
    maxComp[A[x][y]] = max(maxComp[A[x][y]], cnt);
    total[A[x][y]]++;
    for (int x2 = x - 1; x2 <= x + 1; x2++) {
        for (int y2 = y - 1; y2 <= y + 1; y2++) {
            if (x2 != x && y2 != y) continue;
            if (x2 == x && y2 == y) continue;
            if (x2 < 1 || x2 > N) continue;
            if (y2 < 1 || y2 > N) continue;
            if (A[x][y] != A[x2][y2]) continue;
            DFS(x2, y2);
        }
    }
}

void DFS2(int x, int y, int t1, int t2) {
    if (seen[x][y]) return;
    seen[x][y] = true;
    cnt++;
    maxComp2 = max(maxComp2, cnt);
    for (int x2 = x - 1; x2 <= x + 1; x2++) {
        for (int y2 = y - 1; y2 <= y + 1; y2++) {
            if (x2 != x && y2 != y) continue;
            if (x2 == x && y2 == y) continue;
            if (x2 < 1 || x2 > N) continue;
            if (y2 < 1 || y2 > N) continue;
            if (A[x2][y2] != t1 && A[x2][y2] != t2) continue;
            DFS2(x2, y2, t1, t2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    // One Cow
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (seen[i][j]) continue;
            cnt = 0;
            DFS(i, j);
        }
    }
    int ans1 = 0;
    vector<int> vals;
    for (int i = 0; i <= MAX_A; i++) {
        if (!maxComp[i]) continue;
        ans1 = max(ans1, maxComp[i]);
        vals.push_back(i);
    }
    cout << ans1 << "\n";
    // Two Cows
    sort(vals.begin(), vals.end(), cmp);
    int M = (int)vals.size();
    int L = 0;
    int R = 1;
    int ans2 = 0;
    while (L < M && R < M) {
        if (total[vals[L]] + total[vals[R]] <= ans2) {
            L++;
            R = L + 1;
            continue;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                seen[i][j] = false;
            }
        }
        maxComp2 = 0;
        int t1 = vals[L];
        int t2 = vals[R];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (A[i][j] != t1 &&
                    A[i][j] != t2) continue;
                if (seen[i][j]) continue;
                cnt = 0;
                DFS2(i, j, t1, t2);
            }
        }
        ans2 = max(ans2, maxComp2);
        R++;
    }
    cout << ans2 << "\n";
}
