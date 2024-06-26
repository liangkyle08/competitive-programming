#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[200001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1);
    multiset<int> s;
    for (int i = 1; i <= N; i++) {
        if (s.empty() || s.find(arr[i]-1) == s.end()) {
            s.insert(arr[i]);
        }
        else {
            s.erase(s.find(arr[i]-1));
            s.insert(arr[i]);
        }
    }
    cout << (int)s.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
