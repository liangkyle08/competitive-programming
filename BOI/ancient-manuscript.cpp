#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int Ve, Vc, Ce, Cc;
string s;
map<char, int> type;
long long DP[16][ALP + 5][5][5];

void initialize() {
    for (int i = 0; i < 5; i++) {
        type["aeiou"[i]] = true;
    }
}

void check(int i, int j, int k, int p) {
    if (k > 1 && p > 1) {
        DP[i][j][k][p] = DP[i - 1][j][k - 1][p - 1];
    }
    else if (k > 1 && p == 1) {
        for (int j2 = 0; j2 < ALP; j2++) {
            if (type['a' + j2] != type['a' + j] || j == j2) continue;
            for (int p2 = 1; p2 <= (type[s[i - 1]] ? Ve : Vc); p2++) {
                DP[i][j][k][p] += DP[i - 1][j2][k - 1][p2];
            }
        }
    }
    else {
        for (int j2 = 0; j2 < ALP; j2++) {
            if (type['a' + j2] == type['a' + j]) continue;
            for (int k2 = 1; k2 <= min((type[s[i - 1]] ? Vc : Cc), i - 1); k2++) {
                for (int p2 = 1; p2 <= min((type[s[i - 1]] ? Ve : Ce), i -1); p2++) {
                    DP[i][j][k][p] += DP[i - 1][j2][k2][p2];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    initialize();
    cin >> Ve >> Vc >> Ce >> Cc >> s;
    for (int j = 0; j < ALP; j++) {
        if (s[0] != '*' && (s[0] - 'a') != j) continue;
        DP[1][j][1][1] = 1;
    }
    for (int i = 2; i <= (int)s.size(); i++) {
        for (int j = 0; j < ALP; j++) {
            if (s[i - 1] != '*' && (s[i - 1] - 'a') != j) continue;
            for (int k = 1; k <= min((type[s[i - 1]] ? Vc : Cc), i); k++) {
                for (int p = 1; p <= min((type[s[i - 1]] ? Ve : Ce), i); p++) {
                    if (k < p) continue;
                    check(i, j, k, p);
                }
            }
        }
    }
    long long ans = 0;
    for (int j = 0; j < ALP; j++) {
        for (int k = 1; k < 5; k++) {
            for (int p = 1; p < 5; p++) {
                ans += DP[(int)s.size()][j][k][p];
            }
        }
    }
    cout << ans << "\n";
}
