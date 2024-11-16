#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+9;
const int BASE = 9973;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int N, X, Y, L, Q;
string s, t;
int A[MAX_N + 5];
int B[MAX_N + 5];
long long power[MAX_N + 5];
long long aHash[MAX_N + 5];
long long bHash[MAX_N + 5];
long long cHash[MAX_N + 5];

void solve() {
    cin >> X >> Y >> L;
    X++;
    Y++;
    int low = 0;
    int high = L - 1;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        long long curA = (aHash[X + mid] - ((aHash[X] * power[mid]) % MOD) + MOD) % MOD;
        long long curB = (bHash[Y + mid] - ((bHash[Y] * power[mid]) % MOD) + MOD) % MOD;
        long long curC = (cHash[mid] - ((cHash[0] * power[mid]) % MOD) + MOD) % MOD;
        if (curC == (curA + curB) % MOD) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    if (low == 0) {
        if (A[X + low] == B[Y + low]) {
            cout << !(A[X + low] && B[Y + low]) << " ";
            return;
        }
        if (A[X + low + 1] && B[Y + low + 1] && L != 1) {
            cout << 0 << " ";
            return;
        }
        cout << 1 << " ";
        return;
    }
    if (low == L - 1) {
        if (A[X + low] && B[Y + low]) {
            cout << 0 << " ";
            return;
        }
        cout << 1 << " ";
        return;
    }
    if (A[X + low + 1] && B[Y + low + 1] && X + low < N && Y + low < N) {
        cout << 0 << " ";
    }
    else {
        cout << 1 << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> s >> t >> Q;
    for (int i = 1; i <= N; i++) {
        A[i] = s[i - 1] - '0';
        B[i] = t[i - 1] - '0';
    }
    power[0] = 1;
    for (int i = 1; i <= N; i++) {
        power[i] = (power[i - 1] * BASE) % MOD;
    }
    for (int i = 1; i <= N; i++) {
        aHash[i] = (aHash[i - 1] * BASE + A[i]) % MOD;
        bHash[i] = (bHash[i - 1] * BASE + B[i]) % MOD;
        cHash[i] = (cHash[i - 1] * BASE + 1) % MOD;
    }
    while (Q--) {
        solve();
    }
}
