#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int H[1000001];
long long Left[1000001];
long long Right[1000001];
long long leftSize[1000001];
long long rightSize[1000001];

void solve1() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    stack<int> s;
    for (int i = 1; i <= N; i++) {
        if (!s.empty() && H[s.top()] > H[i]) {
            while (!s.empty()) s.pop();
        }
        int prev = i;
        while (!s.empty() && H[s.top()] < H[i]) {
            prev = s.top();
            s.pop();
        }
        Left[i] = i-prev+Left[prev];
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = N; i >= 1; i--) {
        if (!s.empty() && H[s.top()] > H[i]) {
            while (!s.empty()) s.pop();
        }
        int prev = i;
        while (!s.empty() && H[s.top()] < H[i]) {
            prev = s.top();
            s.pop();
        }
        Right[i] = prev-i+Right[prev];
        s.push(i);
    }
    for (int i = 1; i <= N; i++) {
        cout << Left[i]+Right[i]+1 << " ";
    } cout << "\n";
}

void solve2() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    stack<int> s;
    for (int i = 1; i <= N; i++) {
        Left[i] = 1;
        leftSize[i] = 1;
        while (!s.empty() && H[s.top()] < H[i]) {
            Left[i] += Left[s.top()]+(leftSize[s.top()])*(H[i]-H[s.top()]);
            leftSize[i] += leftSize[s.top()];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = N; i >= 1; i--) {
        Right[i] = 1;
        rightSize[i] = 1;
        while (!s.empty() && H[s.top()] < H[i]) {
            Right[i] += Right[s.top()]+(rightSize[s.top()])*(H[i]-H[s.top()]);
            rightSize[i] += rightSize[s.top()];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 1; i <= N; i++) {
        cout << Left[i]+Right[i]-1 << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    if (T == 1) solve1();
    else solve2();
}
