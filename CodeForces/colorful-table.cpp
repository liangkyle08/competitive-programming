#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
int arr[100001];
int L[100001];
int R[100001];
bool seen[100001];

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        L[i] = 0;
        R[i] = 0;
        seen[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        seen[arr[i]] = true;
        if (!L[arr[i]]) {
            L[arr[i]] = i;
        }
        R[arr[i]] = i;
    }
    int prevInd = -1;
    for (int i = K; i >= 1; i--) {
        if (!seen[i]) continue;
        if (prevInd == -1) {
            prevInd = i;
            continue;
        }
        if (R[prevInd] > R[i]) {
            R[i] = R[prevInd];
        }
        if (L[prevInd] < L[i]) {
            L[i] = L[prevInd];
        }
        prevInd = i;
    }
    for (int i = 1; i <= K; i++) {
        //cout << i << " " << L[i] << " " << R[i] << "\n";
        if (!seen[i]) {
            cout << 0 << " ";
            continue;
        }
        cout << 2*(R[i]-L[i]+1) << " ";
    } cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
