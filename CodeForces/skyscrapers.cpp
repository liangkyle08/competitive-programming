#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long arr[500005];
long long leftCnt[500005];
long long rightCnt[500005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    stack<int> s;
    for (int i = 1; i <= N; i++) {
        leftCnt[i] = arr[i];
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            leftCnt[i] += arr[i]*(i-s.top()-1)+leftCnt[s.top()];
        }
        else {
            leftCnt[i] += arr[i]*(i-1);
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = N; i >= 1; i--) {
        rightCnt[i] = arr[i];
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            rightCnt[i] += arr[i]*(s.top()-i-1)+rightCnt[s.top()];
        }
        else {
            rightCnt[i] += arr[i]*(N-i);
        }
        s.push(i);
    }
    long long maxVal = 0;
    int ind = 0;
    for (int i = 1; i <= N; i++) {
        long long total = leftCnt[i]+rightCnt[i]-arr[i];
        if (total >= maxVal) {
            maxVal = total;
            ind = i;
        }
    }
    vector<int> ans(N+1);
    int cur = arr[ind];
    for (int i = ind; i <= N; i++) {
        if (arr[i] < cur) cur = arr[i];
        ans[i] = cur;
    }
    cur = arr[ind];
    for (int i = ind; i >= 1; i--) {
        if (arr[i] < cur) cur = arr[i];
        ans[i] = cur;
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}
