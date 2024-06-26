#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    vector<pair<int, int>> edges;
    edges.push_back({0, -1});
    int cnt = 1;
    int node = 0;
    while (K >= cnt) {
        K -= cnt;
        edges.push_back({node+1, node});
        node++;
        cnt++;
    }
    if (K) {
        edges.push_back({node+1, K-1});
    }
    cout << (int)edges.size() << "\n";
    for (auto [u, v]: edges) {
        cout << u << " " << v << "\n";
    }
}
