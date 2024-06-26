#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
bool seen[1000005];
int upperBound[1000005];
int L[1000005];
int R[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sirpal.in", "r", stdin);
    freopen("sirpal.out", "w", stdout);
    cin >> N;
    vector<int> s;
    for (int i = 1; i <= N; i++) {
        int val;
        cin >> val;
        if (L[val] == 0) {
            L[val] = i;
        }
        R[val] = i;
        if (!seen[val]) {
            s.push_back(val);
            seen[val] = true;
        }
    }
    for (auto v: s) {
        if (R[v] - L[v] >= 2) {
            upperBound[L[v]+1] = max(upperBound[L[v]+1], R[v]-1);
        }
    }
    int next = 0;
    for (int i = 1; i <= N; i++) {
        next = max(next, upperBound[i]);
        cout << (i <= next);
    } cout << "\n";
}
