#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, H, N;
int A[200001];
int C[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> H >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= N; i++) {
            cin >> C[i];
        }
        priority_queue<pair<long long, int>> pq;
        for (int i = 1; i <= N; i++) {
            pq.push({-1, i});
        }
        long long ans = 0;
        while (H > 0) {
            long long t = -pq.top().fi;
            int ind = pq.top().se;
            pq.pop();
            ans = max(ans, t);
            H -= A[ind];
            pq.push({-(t + C[ind]), ind});
        }
        cout << ans << "\n";
    }
}
