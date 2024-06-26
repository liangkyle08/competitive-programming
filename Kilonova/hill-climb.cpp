#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[100001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int maxLen = 0;
    int curLen = 0;
    int curVal = arr[N];
    for (int i = N-1; i >= 1; i--) {
        if (arr[i] >= curVal) {
            maxLen = max(maxLen, curLen);
            curLen = 0;
            curVal = arr[i];
            continue;
        }
        curLen++;
    }
    maxLen = max(maxLen, curLen);
    cout << maxLen << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
