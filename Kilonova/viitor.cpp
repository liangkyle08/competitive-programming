#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

struct Edge {
  int pos, id;
  bool isStart;
};

bool cmp(Edge A, Edge B) {
    if (A.pos == B.pos) return A.isStart;
    return A.pos < B.pos;
}

int N, M, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    vector<Edge> edges;
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(Edge{u, i, true});
        edges.push_back(Edge{v, i, false});
    }
    sort(edges.begin(), edges.end(), cmp);
    int prevPos = 0;
    set<int> s;
    vector<pair<int, int>> seg;
    for (auto [pos, id, isStart]: edges) {
        if (s.empty()) {
            if (prevPos+1 < pos-1) {
                seg.push_back({prevPos+1, pos-1});
            }
        }
        prevPos = pos;
        if (isStart) {
            s.insert(id);
        }
        else {
            s.erase(id);
        }
    }
    if (prevPos+1 < N) {
        seg.push_back({prevPos+1, N});
    }
}
