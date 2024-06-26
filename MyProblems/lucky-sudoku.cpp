#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int MAX_N = 2e5;
const int MAX_M = 2e5;

int N, M;
int R[MAX_M+1];
int C[MAX_M+1];
int val[MAX_M+1];
map<pair<int, int>, int> seen;
map<pair<int, int>, bool> seen2;
set<int> rows;
set<int> cols;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> R[i] >> C[i] >> val[i];
        // Convert to 0-index so mod is easier to use
        R[i]--; C[i]--;
        seen[{R[i], C[i]}] = val[i];
        if (val[i] != 8) continue;
        rows.insert(R[i]);
        cols.insert(C[i]);
    }
    long long rowCnt = (long long)rows.size();
    long long colCnt = (long long)cols.size();
    long long blocked = N*(rowCnt+colCnt)-(rowCnt*colCnt);
    for (int i = 1; i <= M; i++) { // Only 8s
        if (val[i] != 8) continue;
        int rowShift = 3*(R[i]/3);
        int colShift = 3*(C[i]/3);
        bool flag = false;
        for (int rowAdd = 0; rowAdd <= 2; rowAdd++) {
            for (int colAdd = 0; colAdd <= 2; colAdd++) {
                int r = rowShift+rowAdd;
                int c = colShift+colAdd;
                if (r == R[i] && c == C[i]) continue;
                if (seen2[{r, c}]) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) continue;
        for (int rowAdd = 0; rowAdd <= 2; rowAdd++) {
            for (int colAdd = 0; colAdd <= 2; colAdd++) {
                int r = rowShift+rowAdd;
                int c = colShift+colAdd;
                if (rows.find(r) != rows.end()) continue;
                if (cols.find(c) != cols.end()) continue;
                if (r == R[i] && c == C[i]) continue;
                if (seen[{r, c}]) continue;
                blocked++;
            }
        }
        seen2[{R[i], C[i]}] = true;
    }
    for (int i = 1; i <= M; i++) { // Non-8s
        if (val[i] == 8) continue;
        int rowShift = 3*(R[i]/3);
        int colShift = 3*(C[i]/3);
        bool flag = true;
        if (rows.find(R[i]) != rows.end()) flag = false;
        if (cols.find(C[i]) != cols.end()) flag = false;
        for (int rowAdd = 0; rowAdd <= 2; rowAdd++) {
            for (int colAdd = 0; colAdd <= 2; colAdd++) {
                int r = rowShift+rowAdd;
                int c = colShift+colAdd;
                if (seen[{r, c}] == 8) flag = false;
            }
        }
        blocked += flag;
    }
    long long ans = (long long)N*(long long)N-blocked;
    cout << ans << "\n";
}
