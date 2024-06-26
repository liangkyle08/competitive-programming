#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

long long T;
int N, M;
long long vel[1001];
long long pos[1001];
long long arr[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lemans.in", "r", stdin);
    freopen("lemans.out", "w", stdout);
    cin >> T >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> vel[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> pos[i];
    }
    set<pair<int, int>> dist;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            arr[i][j] = vel[i]*T+pos[j];
            dist.insert({arr[i][j], i});
        }
    }
    vector<int> seen(N+1);
    int cnt = 0;
    deque<pair<long long, int>> dq;
    long long total = (1LL<<60);
    long long L = -1;
    long long R = -1;
    for (auto [cur, v]: dist) {
        dq.push_back({cur, v});
        if (seen[v] == 0) cnt++;
        seen[v]++;
        while (!dq.empty() && cnt == N) {
            if (cur-dq.front().fi < total) {
                total = cur-dq.front().fi;
                L = dq.front().fi;
                R = cur;
            }
            seen[dq.front().se]--;
            if (seen[dq.front().se] == 0) cnt--;
            dq.pop_front();
        }
    }
    vector<int> ans(N+1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] >= L && arr[i][j] <= R) {
                ans[i] = j;
                break;
            }
        }
    }
    cout << total << "\n";
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}