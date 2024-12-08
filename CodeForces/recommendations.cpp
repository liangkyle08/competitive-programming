#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int N;
int A[MAX_N + 5];
int T[MAX_N + 5];
unordered_map<long long, vector<long long>> times;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    set<int> s;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        s.insert(A[i]);
    }
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
        times[A[i]].push_back(T[i]);
    }
    priority_queue<long long> temp;
    long long ans = 0;
    long long total = 0;
    for (auto &v: s) {
        if ((int)times[v].size() == 1 && temp.empty()) continue;
        for (auto &u: times[v]) {
            temp.push(u);
            total += u;
        }
        total -= temp.top();
        temp.pop();
        int cur = v;
        while (!temp.empty()) {
            cur++;
            ans += total;
            if (!times[cur].empty()) break;
            total -= temp.top();
            temp.pop();
        }
    }
    cout << ans << "\n";
}
