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

const int MAX_N = 1e6;

int N, M;
string text, pattern;
long long power[MAX_N + 5];
long long textHash[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> text >> pattern;
    N = text.size();
    M = pattern.size();
    power[0] = 1;
    for (int i = 1; i <= N; i++) {
        power[i] = (power[i - 1] * BASE) % MOD;
    }
    long long patternHash = 0;
    for (int i = 0; i < M; i++) {
        patternHash = (patternHash * BASE + (pattern[i] - 'a')) % MOD;
    }
    for (int i = 1; i <= N; i++) {
        textHash[i] = (textHash[i - 1] * BASE + (text[i - 1] - 'a')) % MOD;
    }
    int cnt = 0;
    for (int i = 0; i <= N - M; i++) {
        long long startHash = textHash[i];
        long long endHash = textHash[i + M];
        long long currHash = (endHash - ((startHash * power[M]) % MOD) + MOD) % MOD;
        cnt += (currHash == patternHash);
    }
    cout << cnt << "\n";
}