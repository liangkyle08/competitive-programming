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
int Q[MAX_N + 5];
int K[MAX_N + 5];
int J[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) cin >> Q[i];
        for (int i = 1; i <= N; i++) cin >> K[i];
        for (int i = 1; i <= N; i++) cin >> J[i];
        set<int> q, k, j;
        vector<pair<char, int>> step(N + 5);
        vector<int> qRev(N + 5), qInd(N + 5);
        vector<int> kRev(N + 5), kInd(N + 5);
        vector<int> jRev(N + 5), jInd(N + 5);
        q.insert(Q[1]); qInd[Q[1]] = 1;
        k.insert(K[1]); kInd[K[1]] = 1;
        j.insert(J[1]); jInd[J[1]] = 1;
        for (int i = 2; i <= N; i++) {
            bool flag = false;
            if (q.lower_bound(Q[i]) != q.end()) {
                step[i] = {'q', i};
                qRev[i] = qInd[*q.lower_bound(Q[i])];
                flag = true;
            }
            else if (k.lower_bound(K[i]) != k.end()) {
                step[i] = {'k', i};
                kRev[i] = kInd[*k.lower_bound(K[i])];
                flag = true;
            }
            else if (j.lower_bound(J[i]) != j.end()) {
                step[i] = {'j', i};
                jRev[i] = jInd[*j.lower_bound(J[i])];
                flag = true;
            }
            else {
                step[i] = {'x', -1};
            }
            if (flag) {
                q.insert(Q[i]);
                qInd[Q[i]] = i;
                k.insert(K[i]);
                kInd[K[i]] = i;
                j.insert(J[i]);
                jInd[J[i]] = i;
            }
        }
        int cur = N;
        vector<pair<char, int>> ans;
        while (cur > 1) {
            if (step[cur].fi == 'x') break;
            ans.push_back(step[cur]);
            if (step[cur].fi == 'q') cur = qRev[cur];
            else if (step[cur].fi == 'k') cur = kRev[cur];
            else if (step[cur].fi == 'j') cur = jRev[cur];
        }
        if (cur != 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << (int)ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for (auto [u, v]: ans) {
            cout << u << " " << v << "\n";
        }
    }
}
