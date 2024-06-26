#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;

int main() {
    cin >> N;
    vector<pair<int, int>> arr(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    sort(arr.begin()+1, arr.end());
    vector<int> ones(N+1);
    vector<int> twos(N+1);
    for (int i = 1; i <= N; i++) {
        ones[i] = ones[i-1];
        twos[i] = twos[i-1];
        if (arr[i].se == 1) {
            ones[i]++;
        }
        else {
            twos[i] += 2;
        }
    }
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = max(ans, ones[i]+twos[N]-twos[i]);
    }
    cout << ans+1000000000 << "\n";
}
