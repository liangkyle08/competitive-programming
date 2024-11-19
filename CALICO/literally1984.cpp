#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, N;
bool seen[1005][1005];
vector<pair<int, int>> ans;

bool cmp(pair<int, int> A, pair<int, int> B) {
    if (A.fi + A.se == B.fi + B.se) {
        return A.fi < B.fi;
    }
    return A.fi + A.se < B.fi + B.se;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (seen[i][j]) continue;
            ans.push_back({i, j});
            int k = i;
            int w = j;
            while (k <= 1000 && w <= 1000) {
                seen[k][w] = true;
                k += i;
                w += j;
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cin >> T;
    while (T--) {
        cin >> N;
        cout << ans[N - 1].fi << " " << ans[N - 1].se << "\n";
    }
}
