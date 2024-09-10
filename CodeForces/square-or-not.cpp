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
int A[MAX_N + 5];
string s;
map<int, int> sq;

void solve() {
    cin >> N >> s;
    for (int i = 1; i <= N; i++) {
        A[i] = s[i - 1] - '0';
    }
    if (!sq[N]) {
        cout << "No\n";
        return;
    }
    int M = sq[N];
    int ind = 1;
    bool ans = true;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 || i == M || j == 1 || j == M) {
                ans &= A[ind];
            }
            else {
                ans &= !A[ind];
            }
            ind++;
        }
    }
    cout << (ans ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i * i <= MAX_N; i++) {
        sq[i * i] = i;
    }
    cin >> T;
    while (T--) {
        solve();
    }
}
