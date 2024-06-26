#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K, B;
bool broken[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    cin >> N >> K >> B;
    for (int i = 0; i < B; i++) {
        int ind;
        cin >> ind;
        broken[ind] = true;
    }
    queue<int> q;
    int ans = B;
    int cur = 0;
    for (int i = 1; i <= N; i++) {
        q.push(i);
        cur += broken[i];
        if (q.size() > K) {
            cur -= broken[q.front()];
            q.pop();
            ans = min(ans, cur);
        }
    }
    cout << ans << "\n";
}
