#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int T, N;
long long A[MAX_N + 5];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    if (N <= 2) {
        cout << -1 << "\n";
        return;
    }
    sort(A + 1, A + N + 1);
    map<long long, int> mx;
    set<long long> vals;
    vals.insert(0);
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        total += A[i];
        vals.insert(A[i]);
        if (i == 1) {
            mx[A[i]] = 1;
            continue;
        }
        mx[A[i]] = mx[A[i - 1]] + 1;
    }
    mx[A[N]]--;
    long long low = 0;
    long long high = 1e12;
    while (low < high) {
        long long mid = (low + high) / 2;
        long long avg = (total + mid) / (long long)(N * 2);
        if ((total + mid) % (long long)(N * 2) == 0) avg--;
        avg = *(--vals.upper_bound(avg));
        if (mx[avg] >= N / 2 + 1) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    cout << low << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
