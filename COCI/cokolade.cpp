#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

int N;
int A[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    set<int> s;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        int div = 1;
        while (true) {
            s.insert(div);
            if (A[i] / div == 0) break;
            div = A[i] / (A[i] / div) + 1;
        }
    }
    vector<int> ans(N+1, -1);
    for (auto div: s) {
        map<int, int> freq;
        for (int i = 1; i <= N; i++) {
            freq[A[i] / div]++;
        }
        for (auto [u, v]: freq) {
            if (ans[v] > -1) continue;
            ans[v] = div;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}
