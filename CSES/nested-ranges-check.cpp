#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
pair<pair<int, int>, int> arr[200001];
bool A[200001];
bool B[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi.fi >> arr[i].fi.se;
        arr[i].fi.se = -arr[i].fi.se;
        arr[i].se = i;
    }
    sort(arr+1, arr+N+1);
    // Ranges that are in another range (B)
    int maxRight = -arr[1].fi.se;
    for (int i = 2; i <= N; i++) {
        if (-arr[i].fi.se <= maxRight) {
            B[arr[i].se] = true;
        }
        maxRight = max(maxRight, -arr[i].fi.se);
    }
    // Ranges that contain another range (A)
    int minRight = -arr[N].fi.se;
    for (int i = N-1; i >= 1; i--) {
        if (-arr[i].fi.se >= minRight) {
            A[arr[i].se] = true;
        }
        minRight = min(minRight, -arr[i].fi.se);
    }
    for (int i = 1; i <= N; i++) {
        cout << A[i] << " ";
    } cout << '\n';
    for (int i = 1; i <= N; i++) {
        cout << B[i] << " ";
    } cout << '\n';
}
