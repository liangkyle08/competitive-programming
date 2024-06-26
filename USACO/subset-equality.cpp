#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

string s, t, q;
int N, M, Q, K;
int A[100001];
int B[100001];
bool match[20][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> s >> t;
    N = (int)s.size();
    M = (int)t.size();
    for (int i = 1; i <= N; i++) {
        A[i] = (s[i-1]-'a')+1;
    }
    for (int i = 1; i <= M; i++) {
        B[i] = (t[i-1]-'a')+1;
    }
    for (int u = 1; u <= 18; u++) {
        for (int v = u; v <= 18; v++) {
            vector<int> s1, s2;
            for (int i = 1; i <= N; i++) {
                if (A[i] != u && A[i] != v) continue;
                s1.push_back(A[i]);
            }
            for (int i = 1; i <= M; i++) {
                if (B[i] != u && B[i] != v) continue;
                s2.push_back(B[i]);
            }
            if ((int)s1.size() != (int)s2.size()) continue;
            bool flag = false;
            for (int i = 0; i < (int)s1.size(); i++) {
                if (s1[i] != s2[i]) {
                    flag = true;
                }
            }
            if (flag) continue;
            match[u][v] = true;
        }
    }
    cin >> Q;
    while (Q--) {
        cin >> q;
        K = (int)q.size();
        vector<int> query(K+1);
        for (int i = 1; i <= K; i++) {
            query[i] = (q[i-1]-'a')+1;
        }
        bool pos = true;
        for (int i = 1; i <= K; i++) {
            for (int j = i; j <= K; j++) {
                if (match[query[i]][query[j]]) continue;
                pos = false;
            }
        }
        if (pos) cout << "Y";
        else cout << "N";
    } cout << "\n";
}
