#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, maxDiff;
int H[10005];
int L[10005];
int R[10005];
vector<int> adjList[10005];
int inDegree[10005];
long long DP[10005];

struct Edge {
    int ind, pos;
    bool isStart;
};

bool cmp(Edge A, Edge B) {
    if (A.pos != B.pos) return A.pos < B.pos;
    if (A.isStart != B.isStart) return A.isStart > B.isStart;
    if (A.isStart && B.isStart) return H[A.ind] < H[B.ind];
    return H[A.ind] > H[B.ind];
}

struct cmp2 {
    bool operator()(const int& A, const int& B) const {
        return H[A] < H[B];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mario.in", "r", stdin);
    freopen("mario.out", "w", stdout);
    cin >> H[1] >> L[1] >> maxDiff >> N;
    vector<Edge> edges;
    edges.push_back(Edge{1, L[1], true});
    for (int i = 2; i <= N+1; i++) {
        cin >> H[i] >> L[i] >> R[i];
        edges.push_back(Edge{i, L[i], true});
        edges.push_back(Edge{i, R[i], false});
    }
    sort(edges.begin(), edges.end(), cmp);
    set<int, cmp2> s;
    for (auto [ind, pos, isStart]: edges) {
        if (isStart) {
            s.insert(ind);
        }
        int adjInd = 0;
        if (s.find(ind) != s.begin()) {
            adjInd = *(--s.find(ind));
        }
        if (H[ind]-H[adjInd] <= maxDiff) {
            adjList[ind].push_back(adjInd);
            inDegree[adjInd]++;
        }
        if (!isStart) {
            s.erase(ind);
        }
    }
    queue<int> q;
    q.push(1);
    DP[1] = 1;
    long long ans = 0;
    vector<int> topOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topOrder.push_back(u);
        for (auto v: adjList[u]) {
            if (v == 0) {
                ans += DP[u];
                continue;
            }
            inDegree[v]--;
            DP[v] += DP[u];
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << ans << "\n";
}
