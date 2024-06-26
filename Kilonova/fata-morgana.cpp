#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, arr[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1);
    if (arr[1] == arr[N/2+1]) {
        for (int i = 1; i <= N; i++) {
            cout << arr[i] << " ";
        } cout << "\n";
        exit(0);
    }
    if (N/2 % 2 == 0) {
        for (int i = 1; i <= N/2; i++) {
            cout << arr[i] << " " << arr[i+N/2] << " ";
        } cout << "\n";
    }
    else {
        for (int i = 1; i < N/2; i++) {
            cout << arr[i] << " " << arr[i+N/2] << " ";
        }
        cout << arr[N] << " " << arr[N/2] << "\n";
    }

}
