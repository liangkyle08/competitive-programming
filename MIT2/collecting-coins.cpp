#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

struct Edge {
    int node, c, r;
};

int N, M;
vector<Edge> adjList[1000001];
long long minCost[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        adjList[a].push_back({b, c, r});
        adjList[b].push_back({a, c, r});
    }
    for (int i = 2; i <= N; i++) {
        minCost[i] = (1LL<<60);
    }
    long long ans = (1LL<<50);
    set<pair<long long, int>> s;
    s.insert({0, 1});
    bool flag = false;
    while (!s.empty()) {
        long long curCost = (*s.begin()).fi;
        int u = (*s.begin()).se;
        s.erase(s.begin());
        if (flag) break;
        for (auto [v, c, r]: adjList[u]) {
            if (curCost+c < minCost[v]) {
                if (minCost[v] != (1LL<<60)) {
                    s.erase({minCost[v], v});
                }
                minCost[v] = curCost+c;
                s.insert({minCost[v], v});
                if (r > c) {
                    ans = min(ans, minCost[v]);
                    flag = true;
                    break;
                }
            }
        }
    }
    ans = min(ans, minCost[N]);
    long long high = ans;
    long long low = 0LL;
    while (low <= high) {
        long long mid = (low+high)/2;
        for (int i = 2; i <= N; i++) {
            minCost[i] = (1LL<<60);
        }
        s.clear();
        s.insert({0, 1});
        flag = false;
        while (!s.empty()) {
            long long curCost = (*s.begin()).fi;
            int u = (*s.begin()).se;
            s.erase(s.begin());
            if (flag) break;
            for (auto [v, c, r]: adjList[u]) {
                if ((curCost+c-r < minCost[v]) && (curCost+c <= mid)) {
                    if (minCost[v] != (1LL<<60)) {
                        s.erase({minCost[v], v});
                    }
                    minCost[v] = curCost+c-r;
                    s.insert({minCost[v], v});
                    if (r > c) {
                        flag = true;
                        break;
                    }
                }
            }
            if (minCost[N] <= ans) flag = true;
            if (flag) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
    }
    cout << ans << "\n";
}
