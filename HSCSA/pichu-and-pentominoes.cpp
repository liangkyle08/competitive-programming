#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;

void solve() {
    cin >> N >> M;
    vector<vector<char>> arr(N+1, vector<char>(M+1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            arr[i][j] = '.';
        }
    }
    int lastJ = 1;
    for (int i = 1; i+1 <= N; i += 2) {
        for (int j = 1; j+4 <= M; j += 5) {
            arr[i][j] = 'A';
            arr[i][j+1] = 'A';
            arr[i][j+2] = 'A';
            arr[i+1][j] = 'A';
            arr[i+1][j+1] = 'A';
            arr[i][j+3] = 'B';
            arr[i][j+4] = 'B';
            arr[i+1][j+2] = 'B';
            arr[i+1][j+3] = 'B';
            arr[i+1][j+4] = 'B';
            lastJ = max(lastJ, j+5);
        }
    }
    for (int j = lastJ; j+1 <= M; j += 2) {
        for (int i = 1; i+4 <= N; i += 5) {
            arr[i][j] = 'C';
            arr[i+1][j] = 'C';
            arr[i][j+1] = 'C';
            arr[i+1][j+1] = 'C';
            arr[i+2][j+1] = 'C';
            arr[i+2][j] = 'D';
            arr[i+3][j] = 'D';
            arr[i+4][j] = 'D';
            arr[i+3][j+1] = 'D';
            arr[i+4][j+1] = 'D';
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 0 && i+2 <= N && j+1 <= M) {
                arr[i][j] = 'E';
                arr[i+1][j] = 'E';
                arr[i][j+1] = 'E';
                arr[i+1][j+1] = 'E';
                arr[i+2][j+1] = 'E';
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j];
        } cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
