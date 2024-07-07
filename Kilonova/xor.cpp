#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 3e5;
const int MAX_V = 128;

int N;
int A[MAX_N+5];
int P[MAX_N+5];
int ind[MAX_V+5];
int ans[MAX_N+5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        P[i] = P[i-1] ^ A[i];
        ind[P[i]] = i;
    }
    for (int v = 0; v < MAX_V; v++) {
        vector<int> diff(N+1);
        for (int i = 1; i <= N; i++) {
            int j = ind[v ^ P[i-1]];
            if (j < i) continue;
            diff[i]++;
            diff[j+1]--;
        }
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += diff[i];
            if (sum) {
                ans[i] = max(ans[i], v);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}