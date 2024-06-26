#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long long A[200005];
long long pSum[200005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A+1, A+N+1);
    for (int i = 1; i <= N; i++) {
        pSum[i] = pSum[i-1]+A[i];
    }
    long long ans = pSum[N];
    for (int i = N; i >= 1; i--) {
        long long L = pSum[i-1];
        long long R = pSum[N]-pSum[i-1];
        //cout << L << " " << R << "\n";
        if (R <= L) {
            ans = min(ans, L+(N-i+1));
            //cout << "P: " << L+(N-i+1) << "\n";
            continue;
        }
        long long diff = (R-L+1)/2;
        if (diff >= A[i]) break;
        ans = min(ans, L+diff+(N-i+1));
        //cout << "P: " << L+diff+(N-i+1) << "\n";
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
