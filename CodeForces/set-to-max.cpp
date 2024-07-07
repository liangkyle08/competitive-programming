#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);

const int MAX_N = 2e5;

int T, N;
int A[MAX_N+1];
int B[MAX_N+1];
bool pos[MAX_N+1];

void solve() {
    cin >> N;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(pos, 0, sizeof(pos));
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    for (int t = 0; t < 2; t++) {
        vector<int> prevB(N+1), nextA(N+1);
        stack<int> s;
        for (int i = N; i >= 1; i--) {
            while (!s.empty() && A[s.top()] <= A[i]) {
                s.pop();
            }
            nextA[i] = (!s.empty() ? s.top() : INF);
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 1; i <= N; i++) {
            while (!s.empty() && B[s.top()] >= B[i]) {
                s.pop();
            }
            prevB[i] = (!s.empty() ? s.top() : 0);
            s.push(i);
        }
        vector<int> ind(N+1);
        for (int i = 1; i <= N; i++) {
            ind[A[i]] = i;
            if (A[i] <= B[i] && ind[B[i]]) {
                if (prevB[i] < ind[B[i]] && nextA[ind[B[i]]] > i) {
                    pos[i] = true;
                }
            }
        }
        reverse(A+1, A+N+1);
        reverse(B+1, B+N+1);
        reverse(pos+1, pos+N+1);
    }
    for (int i = 1; i <= N; i++) {
        if (pos[i]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
