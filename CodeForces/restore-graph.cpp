#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int N, K;
int D[MAX_N + 5];
int maxDepth = 0;
vector<int> depth[MAX_N + 5];
vector<pair<int, int>> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
        maxDepth = max(maxDepth, D[i]);
        depth[D[i]].push_back(i);
    }
    if ((int)depth[0].size() != 1) {
        cout << -1 << "\n";
        return 0;
    }
    bool flag = false;
    for (int i = 0; i < maxDepth; i++) {
        int edgesCnt = K - (i != 0);
        int nodesCnt = 0;
        if (edgesCnt == 0) {
            flag = true;
            break;
        }
        for (auto &v: depth[i + 1]) {
            if (nodesCnt >= (int)depth[i].size()) {
                flag = true;
                break;
            }
            edges.push_back({depth[i][nodesCnt], v});
            edgesCnt--;
            if (edgesCnt == 0) {
                nodesCnt++;
                edgesCnt = K - (i != 0);
            }
        }
        if (flag) break;
    }
    if (flag) {
        cout << -1 << "\n";
        return 0;
    }
    cout << (int)edges.size() << "\n";
    for (auto &[u, v]: edges) {
        cout << u << " " << v << "\n";
    }
}
