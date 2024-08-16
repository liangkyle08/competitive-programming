#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 40;

int T, N;
int X[MAX_N + 5];
int dist[MAX_N + 5];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
    }
    dist[1] = X[2] - X[1];
    dist[N] = X[N] - X[N - 1];
    for (int i = 2; i < N; i++) {
        dist[i] = min(dist[i + 1] - dist[i], dist[i] - dist[i - 1]);
    }
    for (int v = 1; v <= 100; v++) {
        bool flag = false;
        for (int i = 1; i <= N; i++) {
            if (v == X[i]) {
                flag = true;
                break;
            }
            if (dist[i] < abs(X[i] - v)) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        cout << "YES\n";
        return;
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
