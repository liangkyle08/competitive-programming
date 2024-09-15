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
map<int, int> type;
long long DP[16][ALP + 5][5][5];

void initialize() {
    type['a' - 'a'] = true;
    type['e' - 'a'] = true;
    type['i' - 'a'] = true;
    type['o' - 'a'] = true;
    type['u' - 'a'] = true;
}

void check(int i, int j, int k, int p) {
    for (int q = 0; q < ALP; q++) {
        if (s[i] != '*' && s[i] - 'a' != q) continue;
        if (j == q) {
            DP[i + 1][q][k + 1][p + 1] += DP[i][j][k][p];
            continue;
        }
        if (type[j] == type[q]) {
            DP[i + 1][q][k + 1][1] += DP[i][j][k][p];
            continue;
        }
        DP[i + 1][q][1][1] += DP[i][j][k][p];
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
    for (int i = 1; i <= (int)s.size(); i++) {
        for (int j = 0; j < ALP; j++) {
            for (int k = 1; k <= 4; k++) {
                for (int p = 1; p <= 4; p++) {
                    if (!DP[i][j][k][p]) continue;
                    if (type[j] && (p > Ve || k > Vc)) continue;
                    if (!type[j] && (p > Ce || k > Cc)) continue;
                    check(i, j, k, p);
                }
            }
        }
    }
    long long ans = 0;
    for (int j = 0; j < ALP; j++) {
        for (int k = 1; k <= 4; k++) {
            for (int p = 1; p <= 4; p++) {
                if (type[j] && k <= Vc && p <= Ve) {
                    ans += DP[s.size()][j][k][p];
                }
                if (!type[j] && k <= Cc && p <= Ce) {
                    ans += DP[s.size()][j][k][p];
                }
            }
        }
    }
    cout << ans << "\n";
}
