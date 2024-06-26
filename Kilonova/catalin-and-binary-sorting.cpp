#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N;
int arr[200001];
int arr2[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("binsort.in", "r", stdin);
    freopen("binsort.out", "w", stdout);
    cin >> C >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1);
    long long ans = 0;
    if (C == 1) { // Min
        for (int i = 1; i <= N; i++) {
            if (i == N) {
                ans += abs(arr[N]-arr[1]);
            }
            else {
                ans += abs(arr[i]-arr[i+1]);
            }
        }
    }
    else {
        int L = 1;
        int R = N;
        for (int i = 1; i <= N; i++) {
            if (i % 2 == 1) {
                arr2[i] = arr[L];
                L++;
            }
            else {
                arr2[i] = arr[R];
                R--;
            }
        }
        for (int i = 1; i <= N; i++) arr[i] = arr2[i];
        for (int i = 1; i <= N; i++) {
            if (i == N) {
                ans += abs(arr[N]-arr[1]);
            }
            else {
                ans += abs(arr[i]-arr[i+1]);
            }
        }
    }
    cout << ans << "\n";
    for (int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    } cout << "\n";
}
