#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[200001];
int B[200001];
int LArr[200001];
int RArr[200001];

bool initial_check() {
    set<int> s;
    for (int i = 1; i <= N; i++) {
        s.insert(A[i]);
        if (A[i] > B[i]) {
            return true;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (s.find(B[i]) == s.end()) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    if (initial_check()) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= N; i++) {
        LArr[i] = 0;
        RArr[i] = N+1;
    }
    stack<int> stackA;
    stack<int> stackB;
    for (int i = 1; i <= N; i++) {
        while (!stackA.empty() && A[stackA.top()] <= A[i]) {
            RArr[stackA.top()] = min(RArr[stackA.top()], i-1);
            stackA.pop();
        }
        stackA.push(i);
        while (!stackB.empty() && A[stackB.top()] >= B[i]) {
            RArr[stackB.top()] = min(RArr[stackB.top()], i-1);
            stackB.pop();
        }
        stackB.push(i);
    }
    while (!stackA.empty()) stackA.pop();
    while (!stackB.empty()) stackB.pop();
    for (int i = N; i >= 1; i--) {
        while (!stackA.empty() && A[stackA.top()] <= A[i]) {
            LArr[stackA.top()] = max(LArr[stackA.top()], i+1);
            stackA.pop();
        }
        stackA.push(i);
        while (!stackB.empty() && A[stackB.top()] >= B[i]) {
            LArr[stackB.top()] = max(LArr[stackB.top()], i+1);
            stackB.pop();
        }
        stackB.push(i);
    }
    while (!stackA.empty()) stackA.pop();
    while (!stackB.empty()) stackB.pop();
    map<int, vector<int>> X, Y;
    for (int i = 1; i <= N; i++) {
        if (LArr[i] == 0) LArr[i] = i;
        if (RArr[i] == N+1) RArr[i] = i;
        X[LArr[i]].push_back(A[i]);
        Y[RArr[i]].push_back(A[i]);
        cout << LArr[i] << " " << RArr[i] << "\n";
    }
    set<int> s;
    for (int i = 1; i <= N; i++) {
        for (auto v: X[i]) {
            s.insert(v);
        }
        if (!s.empty()) A[i] = *(--s.end());
        for (auto v: Y[i]) {
            s.erase(v);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (A[i] == B[i]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
