#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int N, maxW;
int DP[100001];

int main() {
    cin >> N >> maxW;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].s >> arr[i].f;
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= 100000; i++) DP[i] = maxW;
    int ans = 0;
    for (auto [v, w]: arr) {
        for (int i = 100000-v; i >= 0; i--) {
            if (DP[i]+w <= DP[i+v]) {
                DP[i+v] = DP[i]+w;
                ans = max(ans, i+v);
            }
        }
    }
    cout << ans << "\n";
}
