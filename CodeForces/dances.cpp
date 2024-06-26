#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
int A[100005];
int B[100005];

bool check(int K, int newVal) {
    int i = 1;
    bool flag = true;
    for (int j = 1+K; j <= N; j++) {
        if (A[i-1] < newVal && newVal <= A[i] && flag) {
            flag = false;
            if (newVal >= B[j]) return false;
            continue;
        }
        if (A[i] >= B[j]) return false;
        i++;
    }
    return true;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i < N; i++) {
        cin >> A[i];
    }
    A[N] = (1<<30);
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    sort(A+1, A+N);
    sort(B+1, B+N+1);
    long long high = N;
    long long low = 0;
    while (low < high) {
        int mid = (low+high)/2;
        if (check(mid, 1)) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    long long ans = low;
    high = M+1;
    low = 1;
    while (low < high) {
        int mid = low+(high-low)/2;
        // cout << low << " " << high << "\n";
        if (check(ans, mid)) {
            low = mid+1;
        } else {
            high = mid;
        }
    }
    //cout << low << " " << ans << "\n";
    if (low == M+1) {
        cout << ans*M << '\n';
        return;
    }
    cout << ans*(low-1)+(M-low+1)*(ans+1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
