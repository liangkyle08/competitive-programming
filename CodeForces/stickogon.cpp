#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int A[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> freq(101);
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            freq[A[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += freq[i] / 3;
        }
        cout << ans << "\n";
    }
}
