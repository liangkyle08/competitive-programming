#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, P, Q;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("expresie.in", "r", stdin);
    freopen("expresie.out", "w", stdout);
    cin >> N >> P >> Q >> s;
    vector<long long> A(N+1);
    for (int i = 1; i <= N; i++) {
        A[i] = 1LL*(s[i-1]-'0');
    }
    long long total = 0LL;
    long long sum = 0LL;
    for (int i = 1; i <= (N-P-Q); i++) {
        sum += 1LL*A[i]*(long long)powl(10LL, N-P-Q-i);
    }
    for (int i = N-P-Q; i <= N; i++) {
        if (i > N-P-Q) {
            sum %= (long long)powl(10LL, N-P-Q-1);
            sum *= 10LL;
            sum += 1LL*A[i];
        }
        vector<long long> spare;
        for (int j = 1; j <= N; j++) {
            if (i-(N-P-Q)+1 <= j && j <= i) continue;
            spare.push_back(A[j]);
        }
        sort(spare.begin(), spare.end());
        long long cur = sum;
        for (int j = 0; j < Q; j++) {
            cur -= 1LL*spare[j];
        }
        for (int j = Q; j < (int)spare.size(); j++) {
            cur += 1LL*spare[j];
        }
        total = max(total, cur);
    }
    cout << total << "\n";
}
