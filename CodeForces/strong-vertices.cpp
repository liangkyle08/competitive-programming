#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[200001];
int B[200001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    vector<int> C(N+1);
    for (int i = 1; i <= N; i++) {
        C[i] = A[i]-B[i];
    }
    int mx = *max_element(C.begin()+1, C.end());
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (C[i] == mx) {
            ans.push_back(i);
        }
    }
    cout << (int)ans.size() << "\n";
    for (auto v: ans) {
        cout << v << " ";
    } cout << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
