#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int N;
int A[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<bool> seen(N, false);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += A[i];
        if (cnt == 0) continue;
        seen[i] = true;
        cnt--;
    }
    if (cnt != 0) {
        for (int i = 0; i < N; i++) {
            if (seen[i]) continue;
            cnt--;
            if (cnt > 0) continue;
            rotate(A, A + i + 1, A + N);
            break;
        }
    }
    int ind = N - 1;
    long long ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        while (A[i] > 0) {
            ans += (long long)powl(ind - i, 2);
            ind--;
            A[i]--;
        }
    }
    cout << ans << "\n";
}
