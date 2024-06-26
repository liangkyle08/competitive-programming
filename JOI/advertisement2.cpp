#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
pair<int, int> arr[500001]; // pow, pos
stack<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    sort(arr+1, arr+N+1);
    for (int i = 1; i <= N; i++) {
        if (!s.empty() && arr[i].fi-s.top().fi <= s.top().se-arr[i].se) {
            continue;
        }
        while (!s.empty() && arr[i].fi-s.top().fi <= arr[i].se-s.top().se) {
            s.pop();
        }
        s.push(arr[i]);
    }
    cout << s.size() << '\n';
}
