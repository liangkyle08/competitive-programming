#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[200001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int ans1 = (N+1)/2;
    for (int i = (N+1)/2; i >= 1; i--) {
        if (arr[i] == ans1) {
            ans1--;
        }
    }
    int ans2 = N/2+1;
    for (int i = N/2+1; i <= N; i++) {
        if (arr[i] == ans2) {
            ans2++;
        }
    }
    cout << min(ans1, N-ans2+1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
