#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
vector<int> arr[101];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < N; j++) {
            int a;
            cin >> a;
            arr[i].push_back(a);
        }
    }
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        set<int> s;
        int val = 0;
        for (int j = 1; j <= N; j++) {
            if (!arr[j].empty()) {
                if (s.find(arr[j].back()) != s.end()) {
                    val = arr[j].back();
                    ans.push_back(val);
                    break;
                }
                s.insert(arr[j].back());
            }
        }
        s.clear();
        for (int j = 1; j <= N; j++) {
            if (!arr[j].empty() && arr[j].back() == val) {
                arr[j].pop_back();
            }
        }
        s.clear();
    }
    reverse(ans.begin(), ans.end());
    for (auto v: ans) {
        cout << v << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
