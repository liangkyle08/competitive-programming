#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 10;
const int MAX_A = 1e5;

int T, N;
int A[MAX_N + 5];
int B[MAX_N + 5];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int pow3 = (int)pow(3, N);
    for (int k = 1; k < pow3; k++) {
        int kCp = k;
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            int s = kCp % 3;
            kCp /= 3;
            if (s == 2) s = -1;
            sum += s * A[i];
        }
        if (sum == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
