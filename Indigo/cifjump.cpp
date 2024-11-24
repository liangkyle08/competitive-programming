#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e6;

int N;
int A[MAX_N + 5];
int seen[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    stack<int> s;
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        s.push(i);
        while (!s.empty()) {
            int u = s.top();
            if (seen[u] == 2) break;
            if (seen[u] == 1) {
                int cur = 1;
                seen[u] = 2;
                s.pop();
                while (!s.empty() && s.top() != u) {
                    cur++;
                    seen[s.top()] = 2;
                    s.pop();
                }
                ans = max(ans, cur);
                break;
            }
            seen[u] = 1;
            int v = ((u + A[u] > N) ? (u + A[u] - N) : (u + A[u]));
            s.push(v);
        }
        while (!s.empty()) {
            seen[s.top()] = 2;
            s.pop();
        }
    }
    cout << ans << "\n";
}
