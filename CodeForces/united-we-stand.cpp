#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[101];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1);
    int lenB = 0;
    int lenC = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == arr[N]) {
            lenC++;
        }
        else {
            lenB++;
        }
    }
    if (lenB == 0 || lenC == 0) {
        cout << -1 << "\n";
    }
    else {
        cout << lenB << " " << lenC << "\n";
        for (int i = 1; i <= lenB; i++) {
            cout << arr[i] << " ";
        } cout << "\n";
        for (int i = lenB+1; i <= N; i++) {
            cout << arr[i] << " ";
        } cout << "\n";
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
