#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e6;

int N, target;
int val[MAX_N + 5];
vector<int> adjList[MAX_N + 5];
unordered_map<long long, long long> cnt;
long long ans = 0;

void DFS(int node, int parent, long long sum) {
    sum += val[node];
    ans += cnt[sum - target];
    cnt[sum]++;
    for (auto child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node, sum);
    }
    cnt[sum]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("arbore3.in", "r", stdin);
    freopen("arbore3.out", "w", stdout);
    cnt[0] = 1;
    cin >> N >> target;
    for (int u = 1; u <= N; u++) {
        int v, curVal;
        cin >> v >> curVal;
        if (v != 0) {
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }
        val[u] = curVal;
    }
    DFS(1, 0, 0);
    cout << ans << "\n";
}
