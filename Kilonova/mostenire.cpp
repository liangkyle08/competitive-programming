#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int low = 0;
    int high = N;
    while (low < high) {
        int mid = (low+high)/2;
        if (check(mid)) {
            
        }
        else {

        }
    }
}
