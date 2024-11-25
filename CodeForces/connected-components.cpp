#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int N, M;
vector<int> adjList[MAX_N + 5];
set<int> nodes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        nodes.insert(i);
    }
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (nodes.find(i) == nodes.end()) continue;
        queue<int> q;
        q.push(i);
        int cnc = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            nodes.erase(u);
            set<int> remainingNodes;
            for (auto &v: adjList[u]) {
                if (nodes.find(v) == nodes.end()) continue;
                remainingNodes.insert(v);
            }
            for (auto &v: nodes) {
                if (remainingNodes.find(v) != remainingNodes.end()) continue;
                q.push(v);
            }
            cnc += (int)nodes.size() - (int)remainingNodes.size();
            nodes.clear();
            nodes = remainingNodes;
        }
        ans.push_back(cnc);
    }
    sort(ans.begin(), ans.end());
    cout << (int)ans.size() << "\n";
    for (auto &v: ans) {
        cout << v << " ";
    } cout << "\n";
}
