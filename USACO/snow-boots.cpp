#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;
const int MAX_B = 1e5;

int N, B;
int prv[MAX_N + 5];
int nxt[MAX_N + 5];
pair<int, int> depth[MAX_N + 5];
array<int, 3> boots[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> N >> B;
    for (int i = 1; i <= N; i++) {
        cin >> depth[i].fi;
        depth[i].se = i;
        if (i > 1) prv[i] = i - 1;
        if (i <= N) nxt[i] = i + 1;
    }
    sort(depth + 1, depth + N + 1);
    for (int i = 1; i <= B; i++) {
        cin >> boots[i][0] >> boots[i][1];
        boots[i][2] = i;
    }
    sort(boots + 1, boots + B + 1);
    reverse(boots + 1, boots + B + 1);
    vector<bool> ans(B + 5);
    int cur = N;
    int maxDist = 1;
    for (int i = 1; i <= B; i++) {
        int maxDepth = boots[i][0];
        int dist = boots[i][1];
        int ind = boots[i][2];
        while (cur > 0 && depth[cur].fi > maxDepth) {
            int depthInd = depth[cur].se;
            nxt[prv[depthInd]] = nxt[depthInd];
            prv[nxt[depthInd]] = prv[depthInd];
            maxDist = max(maxDist, nxt[prv[depthInd]] - prv[nxt[depthInd]]);
            cur--;
        }
        ans[ind] = dist >= maxDist;
    }
    for (int i = 1; i <= B; i++) {
        cout << ans[i] << "\n";
    }
}
