#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[100001];
int slope[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++) {
        slope[i] = arr[i+1]-arr[i];
    }
    bool flag1 = true;
    for (int i = 1; i < N-1; i++) {
        if (slope[i] == slope[i+1]) continue;
        flag1 = false;
    }
    bool flag2 = true;
    for (int i = 1; i < N; i++) {
        if (slope[i] == 1 || slope[i] == -1) continue;
        flag2 = false;
    }
    if (flag1 || flag2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

}
