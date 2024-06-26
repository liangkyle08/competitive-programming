#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int L[100001];
int R[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    set<int> endPos;
    map<int, int> ind;
    int seen = 0;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        if (R[i]-L[i] < 74) continue;
        seen++;
        endPos.insert(L[i]+74);
        ind[L[i]+74] = seen;
    }
    endPos.insert(INT_MAX);
    seen = 0;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (R[i]-L[i] < 74) continue;
        auto it = --endPos.upper_bound(R[i]-74+K);
        ans = max(ans, ind[*it]-seen);
        seen++;
    }
    if (K < 75) ans = 0;
    cout << ans << "\n";
}
