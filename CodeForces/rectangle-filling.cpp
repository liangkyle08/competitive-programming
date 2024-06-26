#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
int A[501][501];

bool check(int f) {
    int minX = N+1;
    int maxX = 0;
    int minY = M+1;
    int maxY = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i][j] != f) continue;
            minX = min(minX, i);
            maxX = max(maxX, i);
            minY = min(minY, j);
            maxY = max(maxY, j);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i][j] == f) continue;
            if (minX <= i && i <= maxX
                && minY <= j && j <= maxY) continue;
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        map<pair<int, int>, bool> corners;
        for (int i = 1; i <= N; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= M; j++) {
                A[i][j] = (s[j-1] == 'B');
            }
        }
        if (check(1) || check(0)) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}
