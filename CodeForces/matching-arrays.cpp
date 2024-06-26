#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, X;
pair<int, int> A[200001];
int B[200001];

void solve() {
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> A[i].fi;
        A[i].se = i;
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    sort(A+1, A+N+1);
    sort(B+1, B+N+1);
    rotate(B+1, B+X+1, B+N+1);
    bool pos = true;
    for (int i = N-X+1; i <= N; i++) {
        if (A[i].fi > B[i]) continue;
        pos = false;
    }
    for (int i = 1; i <= N-X; i++) {
        if (A[i].fi <= B[i]) continue;
        pos = false;
    }
    if (!pos) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = 1; i <= N; i++) {
            cout << A[i].se << " ";
        } cout << "\n";
        for (int i = 1; i <= N; i++) {
            cout << B[A[i].se] << " ";
        } cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
