#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;
const int BASE = uniform_int_distribution<long long>(0, MOD - 1)(rng);
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 5e5;

int N;
string s;
bool A[MAX_N + 5];
long long power[20];

bool check(int len) {
    vector<bool> seen(power[len] + 5, false);
    long long val = 0;
    for (int i = 1; i < len; i++) {
        val += power[i - 1] * A[i];
    }
    for (int i = len; i <= N; i++) {
        val += power[len - 1] * A[i];
        seen[val] = true;
        //cout << val << "\n";
        val /= 2;
    }
    for (int i = 0; i < power[len]; i++) {
        if (seen[i]) continue;
        cout << len << "\n";
        for (int j = 0; j < len; j++) {
            cout << (i & (1 << j) ? 'b' : 'a');
        } cout << "\n";
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> N >> s;
    for (int i = 1; i <= N; i++) {
        A[i] = s[i - 1] - 'a';
    }
    power[0] = 1;
    for (int i = 1; i <= 19; i++) {
        power[i] = 2 * power[i - 1];
    }
    for (int i = 1; i <= 19; i++) {
        if (check(i)) break;
    }
}