#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N;
long long K;
string s;
long long val[26];
long long arr[200001];
long long pSum[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pietricele.in", "r", stdin);
    freopen("pietricele.out", "w", stdout);
    cin >> C >> N >> K >> s;
    for (int i = 0; i < 26; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= N; i++) {
        arr[i] = val[(s[i-1]-'a')];
        pSum[i] = pSum[i-1]+arr[i];
    }
    if (C == 1) {
        long long ans = 0;
        for (int i = 1; i <= N; i++) {
            ans = max(ans, arr[i]);
        }
        for (int i = 0; i < K; i++) {
            ans = max(ans, pSum[i+N-(K-1)]-pSum[i]);
        }
        cout << ans << "\n";
    }
    else {
        long long high = pSum[N]/K;
        long long low = 0;
        while (low < high) {
            long long mid = low+(high-low+1)/2;
            int cnt = 0;
            long long sum = 0;
            for (int i = 1; i <= N; i++) {
                sum += arr[i];
                if (sum >= mid) {
                    cnt++;
                    sum = 0;
                }
            }
            if (cnt < K) {
                high = mid-1;
            }
            else {
                low = mid;
            }
        }
        cout << low << "\n";
    }
}
