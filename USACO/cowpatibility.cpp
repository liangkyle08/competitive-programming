#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

long long N;
int arr[6][50001];
set<int> adjList[50001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("cowpatibility.in", "r", stdin);
    //freopen("cowpatibility.out", "w", stdout);
    cin >> N;
    map<int, vector<int>> freq;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> arr[j][i];
            freq[arr[j][i]].push_back(i);
        }
    }
    for (auto [t, s]: freq) {
        for (int i = 0; i < (int)s.size()-1; i++) {
            adjList[s[i]].insert(s[i+1]);
            adjList[s[i+1]].insert(s[i]);
        }
    }
    long long ans = N*(N-1);
    for (int i = 1; i <= N; i++) {
        ans -= (int)adjList[i].size();
    }
    ans /= 2;
    cout << ans << "\n";
}
