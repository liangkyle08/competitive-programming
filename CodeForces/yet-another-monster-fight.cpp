#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[300005];
int maxRight[300005];
int maxLeft[300005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        maxLeft[i] = max(maxLeft[i-1]+1, arr[i]);
    }
    for (int i = N; i >= 1; i--) {
        maxRight[i] = max(maxRight[i+1]+1, arr[i]);
    }
    int ans = (1<<30);
    for (int i = 1; i <= N; i++) {
        ans = min(ans, max(arr[i], max(maxLeft[i-1]+N-i+1, maxRight[i+1]+i)));
    }
    cout << ans << "\n";
}
