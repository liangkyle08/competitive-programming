#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int N, A, B;
int P[MAX_N + 5];
unordered_map<int, vector<int>> ind;
unordered_map<int, vector<pair<int, int>>> adjList;
unordered_map<int, bool> seen;
vector<int> buffer;
int len;
int loop;
vector<pair<int, bool>> edge;
int ans[MAX_N + 5];

void DFS1(int u) {
    if (seen[u]) return;
    seen[u] = true;
    buffer.push_back(u);
    len++;
    for (auto [v, t]: adjList[u]) {
        if (u == v) {
            edge.push_back({t, true});
            loop++;
        }
        if ((int)adjList[u].size() == 1) {
            edge.push_back({t, false});
        }
        DFS1(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> A >> B;
    set<int> vals;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        ind[P[i]].push_back(i);
        vals.insert(P[i]);
    }
    for (auto &v: vals) {
        if (vals.find(A - v) != vals.end()) {
            adjList[v].push_back({A - v, 1});
        }
        if (vals.find(B - v) != vals.end()) {
            adjList[v].push_back({B - v, 2});
        }
    }
    bool flag = false;
    for (auto &v: vals) {
        if (seen[v]) continue;
        len = 0;
        loop = 0;
        edge.clear();
        DFS1(v);
        int t = 1;
        if (len % 2 == 1) {
            if (loop == 0) {
                flag = true;
                break;
            }
            else {
                if (!edge.empty()) t = edge.back().fi;
            }
        }
        else {
            if (loop == 1) {
                while (edge.back().se) edge.pop_back();
                if (!edge.empty()) t = edge.back().fi;
            }
            else {
                if (!edge.empty()) t = edge.back().fi;
            }
        }
        while (!buffer.empty()) {
            for (auto &u: ind[buffer.back()]) {
                ans[u] = t - 1;
            }
            buffer.pop_back();
        }
    }
    if (flag) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}
