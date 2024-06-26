#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

struct Post {
    long long x, y;
};

struct Event {
    long long x, y;
    int id;
    bool isStart;
};

int N, P;
Post A[200005];
pair<Post, int> cowStart[200005];
pair<Post, int> cowEnd[200005];
map<long long, vector<long long>> X, Y;
map<long long, vector<Event>> cowX, cowY;
map<pair<long long, long long>, int> ind;
map<pair<long long, long long>, int> cowInd;
int adj[200005];
int revAdj[200005];
long long totalDist = 0;
long long frontDist[200005];
long long backDist[200005];
int seen[200005];
bool val[200005];
bool rev[200005];
set<int> s;
int ans[200005];

void DFS(int node, int parent, bool flag = false) {
    if (!flag && node == 1) {
        return;
    }
    for (auto x: X[A[node].y]) {
        if (x == A[node].x) continue;
        int child = ind[{x, A[node].y}];
        if (child == parent) continue;
        adj[node] = child;
        revAdj[child] = node;
        DFS(child, node);
        return;
    }
    for (auto y: Y[A[node].x]) {
        if (y == A[node].y) continue;
        int child = ind[{A[node].x, y}];
        if (child == parent) continue;
        adj[node] = child;
        revAdj[child] = node;
        DFS(child, node);
        return;
    }
}

void DFS2(int node, int parent, bool flag = false) {
    if (!flag && node == 1) {
        return;
    }
    int child = adj[node];
    if (A[node].y == A[child].y) { // Check x
        for (auto [x, y, id, isStart]: cowX[A[node].y]) {
            if (x < min(A[node].x, A[child].x) || x > max(A[node].x, A[child].x)) continue;
            if (!seen[id]) {
                seen[id] = true;
                val[id] = isStart;
                frontDist[id] = totalDist+abs(x-A[node].x);
            }
            if (seen[id] && val[id] != isStart) {
                backDist[id] = totalDist+abs(x-A[node].x);
            }
        }
        totalDist += abs(A[node].x-A[child].x);
        DFS2(child, node);
    }
    else {
        for (auto [x, y, id, isStart]: cowY[A[node].x]) {
            if (y < min(A[node].y, A[child].y) || y > max(A[node].y, A[child].y)) continue;
            if (!seen[id]) {
                seen[id] = true;
                val[id] = isStart;
                frontDist[id] = totalDist+abs(y-A[node].y);
            }
            if (seen[id] && val[id] != isStart) {
                backDist[id] = totalDist+abs(y-A[node].y);
            }
        }
        totalDist += abs(A[node].y-A[child].y);
        DFS2(child, node);
    }
}

void DFS3(int node, int parent, bool flag = false) {
    if (!flag && node == 1) {
        ans[node] += (int)s.size();
        return;
    }
    int child = adj[node];
    if (A[node].y == A[child].y) { // Check x
        for (auto [x, y, id, isStart]: cowX[A[node].y]) {
            if (rev[id]) continue;
            if (x < min(A[node].x, A[child].x) || x >= max(A[node].x, A[child].x)) continue;
            if (!seen[id]) {
                seen[id] = true;
                val[id] = isStart;
                s.insert(id);
            }
        }
        ans[node] = (int)s.size();
        for (auto [x, y, id, isStart]: cowX[A[node].y]) {
            if (rev[id]) continue;
            if (x < min(A[node].x, A[child].x) || x >= max(A[node].x, A[child].x)) continue;
            if (seen[id] && val[id] != isStart) {
                s.erase(id);
            }
        }
        DFS3(child, node);
    }
    else {
        for (auto [x, y, id, isStart]: cowY[A[node].x]) {
            if (rev[id]) continue;
            if (y < min(A[node].y, A[child].y) || y > max(A[node].y, A[child].y)) continue;
            if (!seen[id]) {
                seen[id] = true;
                val[id] = isStart;
                s.insert(id);
            }
        }
        ans[node] = (int)s.size();
        for (auto [x, y, id, isStart]: cowY[A[node].x]) {
            if (rev[id]) continue;
            if (y < min(A[node].y, A[child].y) || y > max(A[node].y, A[child].y)) continue;
            if (seen[id] && val[id] != isStart) {
                s.erase(id);
            }
        }
        DFS3(child, node);
    }
}

void DFS4(int node, int parent, bool flag = false) {
    if (!flag && node == 1) {
        ans[node] += (int)s.size();
        return;
    }
    int child = revAdj[node];
    if (A[node].y == A[child].y) { // Check x
        for (auto [x, y, id, isStart]: cowX[A[node].y]) {
            if (!rev[id]) continue;
            if (x < min(A[node].x, A[child].x) || x >= max(A[node].x, A[child].x)) continue;
            if (!seen[id]) {
                seen[id] = true;
                val[id] = isStart;
                s.insert(id);
            }
        }
        ans[node] += (int)s.size();
        for (auto [x, y, id, isStart]: cowX[A[node].y]) {
            if (!rev[id]) continue;
            if (x < min(A[node].x, A[child].x) || x >= max(A[node].x, A[child].x)) continue;
            if (seen[id] && val[id] != isStart) {
                s.erase(id);
            }
        }
        DFS4(child, node);
    }
    else {
        for (auto [x, y, id, isStart]: cowY[A[node].x]) {
            if (!rev[id]) continue;
            if (y < min(A[node].y, A[child].y) || y > max(A[node].y, A[child].y)) continue;
            if (!seen[id]) {
                seen[id] = true;
                val[id] = isStart;
                s.insert(id);
            }
        }
        ans[node] += (int)s.size();
        for (auto [x, y, id, isStart]: cowY[A[node].x]) {
            if (!rev[id]) continue;
            if (y < min(A[node].y, A[child].y) || y > max(A[node].y, A[child].y)) continue;
            if (seen[id] && val[id] != isStart) {
                s.erase(id);
            }
        }
        DFS4(child, node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> P;
    for (int i = 1; i <= P; i++) {
        cin >> A[i].x >> A[i].y;
        X[A[i].y].push_back(A[i].x);
        Y[A[i].x].push_back(A[i].y);
        ind[{A[i].x, A[i].y}] = i;
    }
    for (int i = 1; i <= N; i++) {
        cin >> cowStart[i].fi.x >> cowStart[i].fi.y;
        cowX[cowStart[i].fi.y].push_back({cowStart[i].fi.x, cowStart[i].fi.y, i, false});
        cowY[cowStart[i].fi.x].push_back({cowStart[i].fi.x, cowStart[i].fi.y, i, false});
        cin >> cowEnd[i].fi.x >> cowEnd[i].fi.y;
        cowX[cowEnd[i].fi.y].push_back({cowEnd[i].fi.x, cowEnd[i].fi.y, i, true});
        cowY[cowEnd[i].fi.x].push_back({cowEnd[i].fi.x, cowEnd[i].fi.y, i, true});
        cowStart[i].se = i;
        cowEnd[i].se = i;
    }
    DFS(1, -1, true);
    for (int i = 1; i <= N; i++) {
        seen[i] = false;
        val[i] = -1;
    }
    DFS2(1, -1, true);
    cout << totalDist << "\n";
    for (int i = 1; i <= N; i++) {
        long long curDist = abs(backDist[i]-frontDist[i]);
        if (totalDist-curDist < curDist) {
            rev[i] = true;
        }
        cout << curDist << " " << rev[i] << "\n";
    }
    for (int i = 1; i <= N; i++) {
        seen[i] = false;
        val[i] = -1;
    }
    for (int i = 1; i <= N; i++) {
        if (!rev[i]) {
            DFS3(i, -1, true);
            break;
        }
    }
    s.clear();
    for (int i = 1; i <= N; i++) {
        seen[i] = false;
        val[i] = -1;
    }
    for (int i = 1; i <= N; i++) {
        if (!rev[i]) {
            DFS4(i, -1, true);
            break;
        }
    }
    for (int i = 1; i <= P; i++) {
        cout << ans[i] << "\n";
    }
}
