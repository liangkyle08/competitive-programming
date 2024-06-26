#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int N, maxW;
long long DP[1000001];

int main() {
    cin >> N >> maxW;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].f >> arr[i].s;
    }
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (auto [w, v]: arr) {
        for (int i = maxW-w; i >= 0; i--) {
            if (DP[i] < 0) continue;
            if (DP[i]+v >= DP[i+w]) {
                DP[i+w] = DP[i]+v;
                ans = max(ans, DP[i+w]);
            }
        }
    }
    cout << ans << "\n";
}
