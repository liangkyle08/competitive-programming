#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int R, C, N;
map<int, vector<int>> adjList;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> N;
    set<int> rows;
    map<int, set<int>> coords;
    for (int i = 1; i <= N; i++) {
        int a, b; // row, col
        cin >> a >> b;
        rows.insert(a);
        coords[a].insert(b);
    }
    for (auto a: rows) {
        for (auto b: coords[a]) {
            if (coords[a+1].lower_bound(b) != coords[a+1].end()) {
                adjList
            }
        }
    }
}
