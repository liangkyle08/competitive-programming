#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1000;

int T, N;
long long K;
long long S[MAX_N + 5];

bool solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    sort(S + 1, S + N + 1);
    return S[1] * max(1, 2 * (N - 1) - 1) <= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("..\\MetaHackerCup\\walk-the-line-in.txt", "r", stdin);
    freopen("..\\MetaHackerCup\\walk-the-line-out.txt", "w", stdout);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << (solve() ? "YES" : "NO")  << "\n";
    }
}
