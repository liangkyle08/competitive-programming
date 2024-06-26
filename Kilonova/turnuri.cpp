#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int A[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("turnuri.in", "r", stdin);
    freopen("turnuri.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    vector<int> towerR1(N+1, N+1), towerR2(N+1, N+1);
    vector<int> towerL1(N+1), towerL2(N+1);
    stack<int> s1, s2, temp;
    for (int i = 1; i <= N; i++) {
        while (!s1.empty() && A[s1.top()] < A[i]) {
            temp.push(s1.top());
            towerR1[s1.top()] = i;
            s1.pop();
        }
        while (!s2.empty() && A[s2.top()] < A[i]) {
            towerR2[s2.top()] = i;
            s2.pop();
        }
        while (!temp.empty()) {
            s2.push(temp.top());
            temp.pop();
        }
        s1.push(i);
    }
    while (!s1.empty()) s1.pop();
    while (!s2.empty()) s2.pop();
    for (int i = N; i >= 1; i--) {
        while (!s1.empty() && A[s1.top()] < A[i]) {
            temp.push(s1.top());
            towerL1[s1.top()] = i;
            s1.pop();
        }
        while (!s2.empty() && A[s2.top()] < A[i]) {
            towerL2[s2.top()] = i;
            s2.pop();
        }
        while (!temp.empty()) {
            s2.push(temp.top());
            temp.pop();
        }
        s1.push(i);
    }
    long long sum = 0;
    vector<long long> ans(N+1);
    for (int i = 1; i <= N; i++) {
        sum += towerR1[i] - towerL1[i] - 1;
    }
    for (int i = 1; i <= N; i++) {
        ans[i] = sum - (towerR1[i] - towerL1[i] - 1) + 1;
    }
    for (int i = 1; i <= N; i++) {
        ans[towerL1[i]] += towerL1[i] - towerL2[i];
        ans[towerR1[i]] += towerR2[i] - towerR1[i];
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}
