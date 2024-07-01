#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N, P;

void solve1() {
    cin >> N;
    int nCol = 1;
    int nRow = 1;
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            nCol += nRow;
        }
        if (i % 2 == 1) {
            nRow += nCol;
        }
    }
    cout << nRow << " " << nCol << "\n";
}

void solve2() {
    cin >> N >> P;
    int nCol = 1;
    int nRow = 1;
    int oneCol = 1;
    int oneRow = 1;
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            nCol += nRow;
        }
        if (i % 2 == 1) {
            nRow += nCol;
        }
        if (i % 4 == 0) {
            oneCol += nRow;
        }
        if (i % 4 == 1) {
            oneRow += nCol;
        }
    }
    nCol = 1;
    nRow = 1;
    deque<pair<int, int>> dq;
    if (oneRow == P) {
        dq.push_back({1, 1});
    }
    for (int i = 2; i <= N; i++) {
        if (i % 4 == 0) oneCol -= nRow;
        if (i % 4 == 1) oneRow -= nCol;
        if (i % 4 == 2) oneCol += nCol;
        if (i % 4 == 3) oneRow += nRow;
        if (i % 4 == 0 && oneRow <= P && P <= oneRow+nRow-1) {
            dq.push_front({i, nRow});
        }
        if (i % 4 == 1 && oneRow <= P && P <= oneRow+nCol-1) {
            dq.push_front({i, nCol});
        }
        if (i % 4 == 2 && oneRow <= P && P <= oneRow+nRow-1) {
            dq.push_back({i, nRow});
        }
        if (i % 4 == 3 && oneRow <= P && P <= oneRow+nCol-1) {
            dq.push_back({i, nCol});
        }
        if (i % 4 == 2) oneCol -= nCol;
        if (i % 4 == 3) oneRow -= nRow;
        if (i % 2 == 0) {
            nCol += nRow;
        }
        if (i % 2 == 1) {
            nRow += nCol;
        }
    }
    while (!dq.empty()) {
        for (int i = 0; i < (int)dq.front().se; i++) {
            cout << dq.front().fi << " ";
        }
        dq.pop_front();
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cochilie.in", "r", stdin);
    freopen("cochilie.out", "w", stdout);
    cin >> C;
    if (C == 1) {
        solve1();
    }
    else {
        solve2();
    }
}
