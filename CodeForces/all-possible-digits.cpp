#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 100;

int T, N, P;
int A[MAX_N + 5];
set<int> s;

bool check(int add) {
    int L = -1;
    int R = -1;
    int skip = -1;
    if (A[N] + add >= P) {
        L = (A[N] + add + 1) % P;
        R = A[N] - 1;
        for (int i = N - 1; i >= 1; i--) {
            if (A[i] < P - 1) {
                skip = A[i] + 1;
                break;
            }
        }
        if (skip == -1) skip = 1;
        for (int i = L; i <= R; i++) {
            if (s.find(i) != s.end()) continue;
            if (i == skip) continue;
            return false;
        }
        return true;
    }
    else {
        L = A[N];
        R = A[N] + add;
        for (int i = 0; i < P; i++) {
            if (L <= i && i <= R) continue;
            if (s.find(i) != s.end()) continue;
            if (i == skip) continue;
            return false;
        }
        return true;
    }
}

void solve() {
    cin >> N >> P;
    s.clear();
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        s.insert(A[i]);
    }
    int low = 0;
    int high = P - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
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
