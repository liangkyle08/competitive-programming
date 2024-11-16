#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int T, N, K;
int A[MAX_N + 5];

void solve() {
    cin >> N >> K;
    int singleLoops = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        singleLoops += A[i] == i;
    }
    if (K == 1) {
        cout << (singleLoops == N ? "YES" : "NO") << "\n";
        return;
    }
    vector<int> seen(N + 5);
    vector<int> ind(N + 5);
    bool ans = true;
    int cnc = 1;
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        int node = i;
        int curInd = 1;
        while (!seen[node]) {
            seen[node] = cnc;
            ind[node] = curInd;
            curInd++;
            node = A[node];
        }
        if (seen[node] != cnc) {
            cnc++;
            continue;
        }
        if (curInd - ind[node] != K) {
            ans = false;
            break;
        }
        cnc++;
    }
    cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
