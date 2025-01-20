#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int MAX_N = 5e4;

long long N;
array<int, 5> arr[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
        sort(arr[i].begin(), arr[i].end());
    }
    vector<map<array<int, 5>, int>> common(5);
    for (int i = 1; i <= N; i++) {
        common[4][arr[i]]++;
        for (int a = 0; a < 5; a++) {
            common[0][{arr[i][a]}]++;
            for (int b = a + 1; b < 5; b++) {
                common[1][{arr[i][a], arr[i][b]}]++;
                for (int c = b + 1; c < 5; c++) {
                    common[2][{arr[i][a], arr[i][b], arr[i][c]}]++;
                    for (int d = c + 1; d < 5; d++) {
                        common[3][{arr[i][a], arr[i][b], arr[i][c], arr[i][d]}]++;
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 5; i++) {
        for (auto &[k, v]: common[i]) {
            if (i % 2 == 0) {
                ans += (long long)v * (v - 1) / 2;
            }
            else {
                ans -= (long long)v * (v - 1) / 2;
            }
        }
    }
    cout << (N * (N - 1) / 2 - ans) << '\n';
}
