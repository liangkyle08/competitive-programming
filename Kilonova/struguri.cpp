#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e4;

int T, N;

void solve1() {
    cin >> N;
    vector<int> A(N + 5);
    vector<int> P(N + 5);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        P[i] = P[i - 1] + A[i];
    }
    map<int, int> leftInd, rightInd;
    for (int i = 1; i <= N; i++) {
        rightInd[P[i] % N] = i;
        if (leftInd[P[i] % N] != 0) continue;
        leftInd[P[i] % N] = i;
    }
    int maxLen = 0;
    int finalLeft = 0;
    int finalRight = 0;
    for (auto [v, L]: leftInd) {
        int R = rightInd[v];
        if (R - L <= maxLen) continue;
        maxLen = R - L;
        finalLeft = L + 1;
        finalRight = R;
    }
    if (rightInd[0] > maxLen) {
        maxLen = rightInd[0];
        finalLeft = 1;
        finalRight = rightInd[0];
    }
    cout << maxLen << " " << finalLeft << " " << finalRight << "\n";
}

void solve2() {
    cin >> N;
    vector<int> A(N + 5);
    vector<int> ind;
    vector<int> P(N + 5);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        ind.push_back(i);
    }
    vector<vector<int>> ans;
    while (!ind.empty()) {
        int M = (int)ind.size();
        for (int i = 1; i <= M; i++) {
            P[i] = P[i - 1] + A[ind[i - 1]];
        }
        map<int, int> leftInd, rightInd;
        for (int i = 1; i <= M; i++) {
            rightInd[P[i] % M] = i;
            if (leftInd[P[i] % M] != 0) continue;
            leftInd[P[i] % M] = i;
        }
        vector<array<int, 3>> s;
        for (auto [v, L]: leftInd) {
            int R = rightInd[v];
            if (L == R) continue;
            s.push_back({R - L, L + 1, R});
        }
        if (rightInd[0] != 0) s.push_back({rightInd[0], 1, rightInd[0]});
        sort(s.begin(), s.end());
        vector<bool> seen(M + 1);
        ans.push_back({0, 0, 0});
        while (!s.empty()) {
            int len = s.back()[0];
            int L = s.back()[1];
            int R = s.back()[2];
            s.pop_back();
            bool flag = true;
            for (int i = L; i <= R; i++) {
                if (!seen[i]) continue;
                flag = false;
            }
            if (!flag) continue;
            ans.back()[0] = M;
            ans.back()[2] += len;
            for (int i = L; i <= R; i++) {
                seen[i] = true;
                ans.back()[1] += A[ind[i - 1]];
                ans.back().push_back(ind[i - 1]);
            }
        }
        ans.back()[1] /= M;
        vector<int> buffer;
        for (int i = 1; i <= M; i++) {
            if (seen[i]) continue;
            buffer.push_back(ind[i - 1]);
        }
        ind = buffer;
    }
    cout << (int)ans.size() << "\n";
    for (auto arr: ans) {
        for (auto v: arr) {
            cout << v << " ";
        } cout << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("struguri.in", "r", stdin);
    freopen("struguri.out", "w", stdout);
    cin >> T;
    if (T == 1) {
        solve1();
    }
    else {
        solve2();
    }
}
