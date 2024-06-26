#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
int arr[101];
int diff[101];

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int total = 0;
    priority_queue<int> pq;
    for (int i = 1; i < N; i++) {
        diff[i] = abs(arr[i]-arr[i+1]);
        total += diff[i];
        pq.push(diff[i]);
    }
    K--;
    while (K-- && !pq.empty()) {
        int u = pq.top();
        pq.pop();
        total -= u;
    }
    cout << total << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
