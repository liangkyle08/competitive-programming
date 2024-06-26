#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1);
    map<int, int> leftMostIndex;
    for (int i = 1; i < N; i++) {
        if (leftMostIndex[arr[i]] > 0) continue;
        leftMostIndex[arr[i]] = i;
    }
    int ans = -1;
    for (int i = 1; i < N; i++) {
        int diff = arr[i]-arr[1];
        int j = leftMostIndex[arr[N]-diff];
        if (j == 0) continue;
        if (j <= i+1) {
            ans = max(ans, diff);
        }
    }
    cout << ans << "\n";
}
