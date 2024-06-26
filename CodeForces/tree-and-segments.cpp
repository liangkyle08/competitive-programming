#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
bool arr[3001];

void solve() {
    cin >> N >> K;
    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        arr[i] = (s[i-1] == '1');
    }
    int maxZero = 0;
    int k = K;
    deque<bool> dq;
    for (int i = 1; i <= N; i++) {
        while (k == 0) {
            if (dq.front()) {
                k++;
            }
            dq.pop_front();
        }
        dq.push_back(arr[i]);
        maxZero = max(maxZero, (int)dq.size());
        k--;
    }
    dq.clear();
    int maxOne = 0;
    k = K;
    for (int i = 1; i <= N; i++) {
        while (k == 1) {
            if (dq.front()) {
                k++;
            }
            dq.pop_front();
        }
        dq.push_back(arr[i]);
        maxZero = max(maxZero, (int)dq.size());
        k--;
    }
    for (int j = 1; j <= N; j++) {
        if (j*maxZero)
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
