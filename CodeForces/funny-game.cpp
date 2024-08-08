#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 2000;

int T, N;
int A[MAX_N + 5];
int cnc[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            cnc[i] = i;
        }
        vector<bool> seen(N + 1);
        vector<pair<int, int>> ans;
        for (int i = N - 1; i >= 1; i--) {
            vector<int> occ(i + 1, -1);
            for (int j = 1; j <= N; j++) {
                if (seen[j]) continue;
                if (occ[A[j] % i] != -1) {
                    ans.push_back({j, occ[A[j] % i]});
                    seen[j] = true;
                    break;
                }
                occ[A[j] % i] = j;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        for (auto [u, v]: ans) {
            cout << u << " " << v << "\n";
        }
    }
}
