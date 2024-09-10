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
int P[MAX_N + 5];
bool val[MAX_N + 5];
string s;

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    cin >> s;
    for (int i = 1; i <= N; i++) {
        val[i] = !(s[i - 1] - '0');
    }
    vector<bool> seen(N + 5);
    vector<int> ans(N + 5);
    vector<int> buffer;
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        int next = i;
        int cnt = 0;
        buffer.push_back(i);
        cnt += val[i];
        while (P[next] != i) {
            buffer.push_back(P[next]);
            cnt += val[P[next]];
            next = P[next];
        }
        while (!buffer.empty()) {
            ans[buffer.back()] = cnt;
            seen[buffer.back()] = true;
            buffer.pop_back();
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
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
