#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;
const int BASE = uniform_int_distribution<long long>(0, MOD - 1)(rng);
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;
const int MAX_M = 5e6;

string s, t;
int N, M;
bool A[(int)1e5 + 5];
int cnt[2];
long long power[MAX_M + 5];
long long textHash[MAX_M + 5];

bool check(int n0, int n1) {
    int ind = 0;
    long long patternHash[2] = {-1, -1};
    for (int i = 1; i <= N; i++) {
        int len = (A[i] ? n1 : n0);
        long long startHash = textHash[ind];
        long long endHash = textHash[ind + len];
        long long currHash = (endHash - ((startHash * power[len]) % MOD) + MOD) % MOD;
        if (patternHash[A[i]] == -1) {
            patternHash[A[i]] = currHash;
        }
        else if (patternHash[A[i]] != currHash) {
            return false;
        }
        ind += len;
    }
    if (n0 == n1 && patternHash[0] == patternHash[1]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    N = s.size();
    M = t.size();
    for (int i = 1; i <= N; i++) {
        A[i] = s[i - 1] - '0';
        cnt[A[i]]++;
    }
    power[0] = 1;
    for (int i = 1; i <= M; i++) {
        power[i] = (power[i - 1] * BASE) % MOD;
    }
    for (int i = 1; i <= M; i++) {
        textHash[i] = (textHash[i - 1] * BASE + (t[i - 1] - 'a')) % MOD;
    }
    int ans = 0;
    for (int i = 1; i < M; i++) {
        if ((M - i * cnt[0]) % cnt[1] != 0) continue;
        int j = (M - i * cnt[0]) / cnt[1];
        if (j < 1 || j >= M) continue;
        ans += check(i, j);
    }
    cout << ans << "\n";
}
