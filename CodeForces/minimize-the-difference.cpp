#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
long long A[MAX_N + 5];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    stack<pair<long long, int>> s;
    for (int i = 1; i <= N; i++) {
        long long sum = A[i];
        long long cnt = 1;
        while (!s.empty() && s.top().fi >= sum / cnt) {
            sum += s.top().fi * s.top().se;
            cnt += s.top().se;
            s.pop();
        }
        s.push({sum / cnt, cnt - sum % cnt});
        if (sum % cnt == 0) continue;
        s.push({sum / cnt + 1, sum % cnt});
    }
    long long mx = s.top().fi;
    while ((int)s.size() > 1) s.pop();
    cout << mx - s.top().fi << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
