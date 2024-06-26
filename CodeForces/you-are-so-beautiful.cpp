#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[100001];

void solve() {
    //map<int, int> seenLeft;
    //map<int, int> seenRight;
    map<int, int> lastLeft;
    map<int, int> lastRight;
    map<int, int> cnt;
    cin >> N;
    long long ans = ((long long)N)*((long long)N+1)/2;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        lastLeft[arr[i]] = i;
        if (!lastRight[arr[i]]) {
            lastRight[arr[i]] = i;
        }
        cnt[arr[i]]++;
    }
    for (int i = 1; i <= N; i++) {
        if (cnt[arr[i]] > 1) {
            cout << "P: " << arr[i] << "\n";
            ans -= cnt[arr[i]];
            cnt[arr[i]] = 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (lastLeft[arr[i]] != i) {
            ans -= i-1;
            continue;
        }
    }
    for (int i = N; i >= 1; i--) {
        if (lastRight[arr[i]] != i) {
            ans -= N-i;
            continue;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
