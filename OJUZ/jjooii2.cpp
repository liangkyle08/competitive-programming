#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int N, K;
string str;

int main() {
    cin >> N >> K >> str;
    vector<int> J, O, I;
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] == 'J') {
            J.push_back(i+1);
        }
        else if (str[i] == 'O') {
            O.push_back(i+1);
        }
        else {
            I.push_back(i+1);
        }
    }
    vector<pair<int, int>> A, B, C;
    for (int i = 0; i+K-1 < (int)J.size(); i++) {
        A.emplace_back(J[i], J[K+i-1]);
    }
    for (int i = 0; i+K-1 < (int)O.size(); i++) {
        B.emplace_back(O[i], O[K+i-1]);
    }
    for (int i = 0; i+K-1 < (int)I.size(); i++) {
        C.emplace_back(I[i], I[K+i-1]);
    }
    int a = 0;
    int b = 0;
    int c = 0;
    int ans = INT_MAX;
    while (a < (int)A.size() && b < (int)B.size() && c < (int)C.size()) {
        if (B[b].f < A[a].s) {
            b++;
            continue;
        }
        if (C[c].f < B[b].s) {
            c++;
            continue;
        }
        ans = min(ans, C[c].s-A[a].f-3*K+1);
        a++;
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << "\n";
}

/* Binary Search Sol
int main() {
    cin >> N >> K >> str;
    vector<int> J, O, I;
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] == 'J') {
            J.push_back(i+1);
        }
        else if (str[i] == 'O') {
            O.push_back(i+1);
        }
        else {
            I.push_back(i+1);
        }
    }
    vector<int> A[2], B[2], C[2];
    for (int i = 0; i+K-1 < (int)J.size(); i++) {
        A[0].push_back(J[i]);
        A[1].push_back(J[K+i-1]);
    }
    for (int i = 0; i+K-1 < (int)O.size(); i++) {
        B[0].push_back(O[i]);
        B[1].push_back(O[K+i-1]);
    }
    for (int i = 0; i+K-1 < (int)I.size(); i++) {
        C[0].push_back(I[i]);
        C[1].push_back(I[K+i-1]);
    }
    int ans = INT_MAX;
    for (int a = 0; a < (int)A[0].size(); a++) {
        if (upper_bound(B[0].begin(), B[0].end(), A[1][a]) == B[0].end()) break;
        int b = upper_bound(B[0].begin(), B[0].end(), A[1][a])-B[0].begin();
        if (upper_bound(C[0].begin(), C[0].end(), B[1][b]) == C[0].end()) break;
        int c = upper_bound(C[0].begin(), C[0].end(), B[1][b])-C[0].begin();
        ans = min(ans, C[1][c]-A[0][a]-3*K+1);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << "\n";
}
*/