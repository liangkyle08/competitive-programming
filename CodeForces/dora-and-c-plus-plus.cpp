#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int T, N, A, B;
int C[MAX_N + 5];

void solve() {
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }
    int div = gcd(A, B);
    if (A == B) div = A;
    multiset<int> s;
    for (int i = 1; i <= N; i++) {
        C[i] %= div;
        s.insert(C[i]);
    }
    sort(C + 1, C + N + 1);
    int total = *(--s.end()) - *s.begin();
    for (int i = 1; i <= N; i++) {
        s.erase(s.find(C[i]));
        s.insert(C[i] + div);
        total = min(total, *(--s.end()) - *s.begin());
    }
    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
