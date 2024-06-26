#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nrpits.in", "r", stdin);
    freopen("nrpits.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    stack<int> s;
    vector<int> L(N+1);
    for (int i = 1; i <= N; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            if (i-s.top() >= 2) L[i]++;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    vector<int> R(N+1);
    for (int i = N; i >= 1; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            if (s.top()-i >= 2) R[i]++;
            s.pop();
        }
        s.push(i);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += L[i]+R[i];
    }
    cout << ans << "\n";

}
