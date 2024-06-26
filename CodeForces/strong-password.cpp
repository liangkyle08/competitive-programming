// Educational Codeforces Round 151 (Rated for Div. 2)
// C. Strong Password
// https://codeforces.com/contest/1845/problem/C

#include <bits/stdc++.h>
using namespace std;

int T, M;
string str, leftStr, rightStr;

void solve() {
    cin >> str >> M >> leftStr >> rightStr;
    int N = (int)str.size();
    vector<int> arr(N+1);
    for (int i = 1; i <= N; i++) {
        arr[i] = str[i-1]-'0';
    }
    vector<int> sz(M+1);
    vector<vector<bool>> seen(M+1, vector<bool>(11));
    for (int i = 1; i <= M; i++) {
        int left = leftStr[i-1]-'0';
        int right = rightStr[i-1]-'0';
        for (int j = left; j <= right; j++) {
            sz[i]++;
            seen[i][j] = true;
        }
    }
    int i = 1;
    for (int j = 1; j <= N; j++) {
        if (!sz[i]) {
            if (i == M) break;
            i++;
        }
        if (seen[i][arr[j]]) {
            seen[i][arr[j]] = false;
            sz[i]--;
        }
    }
    if (sz[M]) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
