#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1000;

int N;
int A[MAX_N + 5];
int B[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("AdventOfCode/2024/input.txt", "r", stdin);
    // freopen("AdventOfCode/2024/output.txt", "w", stdout);
    N = 1000;
    map<int, long long> cnt;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        cnt[B[i]]++;
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += A[i] * cnt[A[i]];
    }
    cout << ans << "\n";
}
