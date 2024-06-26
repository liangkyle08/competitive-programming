#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("parcare.in", "r", stdin);
    //freopen("parcare.out", "w", stdout);
    cin >> N >> M >> T;
    vector<pair<pair<int, int>, int>> s;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        s.push_back({{u, 1}, i}); // Enter
        s.push_back({{v, 0}, i}); // Exit
    }
    sort(s.begin(), s.end());
    vector<int> arr(N+1, -1);
    vector<int> pos(M+1, -1);
    stack<int> open;
    for (int i = 1; i <= N; i++) {
        open.push(i);
    }
    for (auto [pi, ind]: s) {
        int u = pi.fi;
        if (u > T) break;
        if (pi.se) { // Enter
            if (open.empty()) continue;
            arr[open.top()] = ind;
            pos[ind] = open.top();
            open.pop();
        }
        else { // Exit
            arr[pos[ind]] = -1;
            open.push(pos[ind]);
        }
    }
    for (int i = 1; i <= M; i++) {
        cout << pos[i] << "\n";
    }
    for (int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    } cout << "\n";
}
