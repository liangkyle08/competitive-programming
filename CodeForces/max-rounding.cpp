#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, K;
string X;
vector<int> arr;

void solve() {
    cin >> X;
    K = X.size();
    arr.clear();
    arr.resize(K+1);
    for (int i = 1; i <= K; i++) {
        arr[i] = X[i-1]-'0';
    }
    int k = K;
    int prev = K+1;
    while (k > 0) {
        if (arr[k] >= 5) {
            while (arr[k-1] == 9 && k > 0) {
                arr[k-1] = 0;
                k--;
            }
            prev = k;
            arr[k-1]++;
        }
        k--;
    }
    if (arr[0] > 0) {
        cout << arr[0];
    }
    for (int i = 1; i <= K; i++) {
        if (i >= prev) {
            cout << 0;
        }
        else {
            cout << arr[i];
        }
    } cout << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
