#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
int arr[1000001];
long long leftCnt[1000001];
long long rightCnt[1000001];
long long suffixSum[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nrsubsecv.in", "r", stdin);
    freopen("nrsubsecv.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    stack<int> s;
    for (int i = 1; i <= N; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            leftCnt[i] = i;
        }
        else {
            leftCnt[i] = i-s.top();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = N; i >= 1; i--) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            rightCnt[i] = N-i+1;
        }
        else {
            rightCnt[i] = s.top()-i;
        }
        s.push(i);
    }
    for (int i = 1; i <= N; i++) {
        suffixSum[arr[i]] += leftCnt[i]*rightCnt[i];
    }
    for (int i = 1000000; i >= 0; i--) {
        suffixSum[i] += suffixSum[i+1];
    }
    while (M--) {
        int u, v;
        cin >> u >> v;
        cout << suffixSum[u]-suffixSum[v+1] << "\n";
    }
}
